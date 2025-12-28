#include<bits/stdc++.h>
using namespace std;
#define ll long long
int r,c,maxn = -1;
int t[10005][10005];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int mem[10005][10005];
int dfs(int x,int y){
    if(mem[x][y]) return mem[x][y];
    for(int i = 0;i < 4;i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx < 0 || ty < 0 || tx >= r || ty >= c) continue;
        if(t[tx][ty] < t[x][y]){
            mem[x][y] = max(mem[x][y],dfs(tx,ty) + 1);
        }
    }
    if(mem[x][y]){
        return mem[x][y];
    }
    return 1;
}
int main() {
    cin>>r>>c;
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            cin>>t[i][j];
        }
    }
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            maxn = max(maxn,dfs(i,j));
        }
    }
    cout<<maxn;
    return 0;
}