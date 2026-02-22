#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n,m;
    cin>>n>>m;
    
    vector<vector<pair<int,int>>> g(n);
    
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    
    for(int i=0;i<n;i++) {
        cout<<i<<":";
        for(int j=g[i].size()-1;j>=0;j--) {
            cout<<"["<<g[i][j].first<<","<<g[i][j].second<<"]";
        }
        cout<<endl;
    }
    
    return 0;
}