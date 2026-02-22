#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool dg[1005][1005];
bool vis[1005];
int n,m,u,v,s,e;
int ans=0;

void addEdge_dg(int u,int v){
    dg[u][v]=1;
    dg[v][u]=1;
}

void dfs(int x){
    if(x==e){
        ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(dg[x][i]&&!vis[i]){
            vis[i]=1;
            dfs(i);
            vis[i]=0;
        }
    }
}

int main() {
    cin>>n>>m;
    for(int i = 0;i < m;i++){
        cin>>u>>v;
        addEdge_dg(u,v);
    }
    cin>>s>>e;
    vis[s]=1;
    dfs(s);
    cout<<ans<<endl;
    return 0;
}