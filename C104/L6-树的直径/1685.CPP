#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int n,deg[N],adj[N][100],h1[N],h2[N],ans;
void dfs_h1h2(int u,int fa){
    h1[u]=h2[u]=0;
    for(int i=0;i<deg[u];++i){
        int v=adj[u][i];
        if(v==fa)continue;
        dfs_h1h2(v,u);
        h2[u]=max(h2[u],h1[v]+1);
        if(h2[u]>h1[u])swap(h2[u],h1[u]);
    }
    ans=max(ans,h1[u]+h2[u]);
}
int main(){
    freopen("diameter.in","r",stdin);
    freopen("diameter.out","w",stdout);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u][deg[u]++]=v;
        adj[v][deg[v]++]=u;
    }
    ans=0;
    dfs_h1h2(1,0);
    cout<<ans<<endl;
    return 0;
}