#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int n,deg[N],adj[N][100];
int down1[N],down2[N],up[N],ans[N];

void dfs_down(int u,int fa){
    down1[u]=down2[u]=0;
    for(int i=0;i<deg[u];++i){
        int v=adj[u][i];
        if(v==fa)continue;
        dfs_down(v,u);
        if(down1[v]+1>down1[u]){
            down2[u]=down1[u];
            down1[u]=down1[v]+1;
        }else if(down1[v]+1>down2[u]){
            down2[u]=down1[v]+1;
        }
    }
}

void dfs_up(int u,int fa){
    for(int i=0;i<deg[u];++i){
        int v=adj[u][i];
        if(v==fa)continue;
        if(down1[v]+1==down1[u]){
            up[v]=max(up[u],down2[u])+1;
        }else{
            up[v]=max(up[u],down1[u])+1;
        }
        dfs_up(v,u);
    }
}

int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u][deg[u]++]=v;
        adj[v][deg[v]++]=u;
    }
    dfs_down(1,0);
    up[1]=0;
    dfs_up(1,0);
    for(int i=1;i<=n;i++){
        ans[i]=max(down1[i],up[i]);
        cout<<ans[i]<<endl;
    }
    return 0;
}
