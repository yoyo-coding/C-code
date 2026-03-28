#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100010;
int n,c,d = 0,d1[N],d2[N];
vector<int> g[N];
void dfs(int u,int fa){
    d1[u] = d2[u] = 0;
    for(size_t i = 0;i<g[u].size();i++){
        int v = g[u][i];
        if(v == fa) continue;
        dfs(v,u);
        int t = d1[v] + 1;
        if(t >d1[u]){
            d2[u] = d1[u];
            d1[u] = t;
        }
        else if(t >d2[u])
            d2[u] = t;
    }
    d = max(d,d1[u]+d2[u]);
}
int main() {
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<d<<endl;
    return 0;
}