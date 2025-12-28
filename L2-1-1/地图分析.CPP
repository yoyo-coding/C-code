#include<bits/stdc++.h>
using namespace std;
int n,ln,sn;
int vis[105][105];
struct node{
    int x,y,step;
    bool island;
}m[105][105];
queue<node> q;
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int bfs(){
    while(!q.empty()) q.pop();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(m[i][j].island == 1){
                m[i][j].step = 0;
                q.push(m[i][j]);
                vis[i][j] = 1;
            }
        }
    }
    int max_dist = 0;
    while(!q.empty()){
        node t = q.front();
        q.pop();
        max_dist = t.step+1;
        for(int i = 0;i < 4;i++){
            int nx = t.x + d[i][0];
            int ny = t.y + d[i][1];
            if(nx < 0||ny < 0||nx >= n||ny >= n){
                continue;
            }
            if(!vis[nx][ny]){
                m[nx][ny].step = t.step + 1;
                vis[nx][ny] = 1;
                q.push(m[nx][ny]);
            }
        
        }
    }
    return max_dist;
}
int main() {
    cin>>n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin>>m[i][j].island;
            m[i][j].x = i;
            m[i][j].y = j;
            if(m[i][j].island == 0)sn++;
            else ln++;
        }
    }
    if(sn == n*n||ln == n*n){
        cout<<-1<<endl;
        return 0;
    }
    cout<<bfs();
    return 0;
}   