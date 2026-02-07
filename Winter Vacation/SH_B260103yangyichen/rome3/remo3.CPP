#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int MAXN = 2005;
int n, m;
char maze[MAXN][MAXN];
bool vis_r[MAXN][MAXN], vis_j[MAXN][MAXN];
int dis_r[MAXN][MAXN], dis_j[MAXN][MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct node {
    int x, y;
    node(int x_=0, int y_=0):x(x_), y(y_){}
};

bool check(int x, int y) {
    if(x < 1 || x > n || y < 1 || y > m) return false;
    if(maze[x][y] == '#') return false;
    return true;
}

double bfs(int rx, int ry, int jx, int jy) {
    queue<node> qr, qj;
    memset(vis_r, 0, sizeof(vis_r));
    memset(vis_j, 0, sizeof(vis_j));
    memset(dis_r, 0x3f, sizeof(dis_r));
    memset(dis_j, 0x3f, sizeof(dis_j));
    
    qr.push(node(rx, ry));
    qj.push(node(jx, jy));
    vis_r[rx][ry] = true;
    vis_j[jx][jy] = true;
    dis_r[rx][ry] = 0;
    dis_j[jx][jy] = 0;
    
    while(!qr.empty() || !qj.empty()) {
        int sz_r = qr.size();
        for(int i = 0; i < sz_r; i++) {
            node cur = qr.front();
            qr.pop();
            int cx = cur.x, cy = cur.y;
            
            if(vis_j[cx][cy]) {
                return (dis_r[cx][cy] + dis_j[cx][cy]) * 0.5;
            }
            
            for(int k = 0; k < 4; k++) {
                int nx = cx + dx[k], ny = cy + dy[k];
                if(check(nx, ny) && !vis_r[nx][ny]) {
                    vis_r[nx][ny] = true;
                    dis_r[nx][ny] = dis_r[cx][cy] + 1;
                    qr.push(node(nx, ny));
                    
                    if(vis_j[nx][ny]) {
                        return (dis_r[nx][ny] + dis_j[nx][ny]) * 0.5;
                    }
                }
            }
        }
        
        int sz_j = qj.size();
        for(int i = 0; i < sz_j; i++) {
            node cur = qj.front();
            qj.pop();
            int cx = cur.x, cy = cur.y;
            
            if(vis_r[cx][cy]) {
                return (dis_r[cx][cy] + dis_j[cx][cy]) * 0.5;
            }
            
            for(int k = 0; k < 4; k++) {
                int nx = cx + dx[k], ny = cy + dy[k];
                if(check(nx, ny) && !vis_j[nx][ny]) {
                    vis_j[nx][ny] = true;
                    dis_j[nx][ny] = dis_j[cx][cy] + 1;
                    qj.push(node(nx, ny));
                    
                    if(vis_r[nx][ny]) {
                        return (dis_r[nx][ny] + dis_j[nx][ny]) * 0.5;
                    }
                }
            }
        }
    }
    
    return -1;
}

int main() {
    freopen("romeo3.in","r",stdin);
    freopen("romeo3.out","w",stdout);
    cin >> n >> m;
    int rx, ry, jx, jy;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> maze[i][j];
            if(maze[i][j] == 'R') {
                rx = i; ry = j;
                maze[i][j] = 'o';
            }
            if(maze[i][j] == 'J') {
                jx = i; jy = j;
                maze[i][j] = 'o';
            }
        }
    }
    
    double res = bfs(rx, ry, jx, jy);
    if(res < 0) cout << "forever" << "\n";
    else cout.precision(1), cout << fixed << res << "\n";
    
    return 0;
}