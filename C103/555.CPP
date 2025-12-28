#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
int n,m,x,vst[N],big;
vector<int> to[N];
vector<int> w[N];
void dfs(int u,int color){
    if(!big)return;
    vst[u] = color;
    for(int i = 0;i < to[u].size();i++){
        if(w[u][i] <= x)continue;
        int v = to[u][i];
        if(!vst[v]){
            dfs(v,color);
        }else{
            if(vst[v] != color){
                big = false;
                return;
            }
        }
    }
}
bool OK(int mid){
    x = mid;
    big = true;
    fill(vst,vst+N+1,0)
    for(int i = 1;i <= n;i++){
        if(!vst[i]){
            dfs(i,1);
        }
    }
    return big;
}
int main() {
    freopen("prison.in","r",stdin);
    freopen("prison.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        to[u].push_back(v);
        to[v].push_back(u);
        w[u].push_back(w);
        w[v].push_back(w);
    }
    int l = 0,r = 1e9;
    
    return 0;
}