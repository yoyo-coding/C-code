#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,vst[50005];
bool Big;
vector<int> to[50005];
void dfs(int u,int color){
    if(!Big)return;
    vst[u] = color;
    for(int i = 0; i < to[u].size(); i++){
        int v = to[u][i];
        if(!vst[v]){
            dfs(v,3 - color);
        }
        else if(vst[v] == color){
            Big = false;
        }
    }    
}
int main() {
    freopen("criminal5.in","r",stdin);
    freopen("criminal5.out","w",stdout);
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        int u,v;
        cin>>u>>v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    Big = true;
    for(int i = 1; i <= n; i++){
        if(!vst[i]){
            dfs(i,1);
        }
    } 
    if(Big){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}