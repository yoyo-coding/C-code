#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool dg[1005][1005];
vector<int> table[1005];
int n,m,u,v; 
void addEdge_dg(int u,int v){
    dg[u][v]=1;
    dg[v][u]=1;
}
void addEdge_table(int u,int v){
    table[u].push_back(v);
    table[v].push_back(u);
}
void out_dg(){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout<<dg[i][j]<<" ";
        }
        cout<<endl;
    }
}
void out_table(){
    for(int i = 1;i <= n;i++){
        sort(table[i].begin(),table[i].end());
    }
    for(int i = 1;i <= n;i++){
        cout<<table[i].size()<<" ";
        int size = table[i].size();
        for(int j = 0;j < size;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    cin>>n>>m;
    for(int i= 0;i < m;i++){
        cin>>u>>v;
        addEdge_dg(u,v);
        addEdge_table(u,v);
    }
    out_dg();
    out_table();
    return 0;
}