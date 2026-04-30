#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2005;
double g[MAXN][MAXN];
double dis[MAXN];
bool vis[MAXN];
int n, m;

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            g[i][j] = 0;
        }
        dis[i] = 0;
        vis[i] = false;
    }
    
    for(int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        double rate = (100.0 - z) / 100.0;
        g[x][y] = rate;
        g[y][x] = rate;
    }
    
    int A, B;
    cin >> A >> B;
    
    dis[A] = 1.0;
    
    for(int i = 1; i <= n; i++) {
        int u = -1;
        double maxv = 0;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && dis[j] > maxv) {
                maxv = dis[j];
                u = j;
            }
        }
        
        if(u == -1) break;
        vis[u] = true;
        
        for(int v = 1; v <= n; v++) {
            if(!vis[v] && g[u][v] > 0) {
                if(dis[u] * g[u][v] > dis[v]) {
                    dis[v] = dis[u] * g[u][v];
                }
            }
        }
    }
    
    double ans = 100.0 / dis[B];
    printf("%.8lf\n", ans);
    
    return 0;
}