#include<bits/stdc++.h>
using namespace std;
int main() {
    int x,y;
    int n,m;
    cin>>n>>m;
    vector<int> a[10010];
    for(int i = 0;i < m;i++){
        cin>>x>>y;
        a[x].push_back(y);
    }
    for(int i = 0;i < m;i++){
        for(size_t j = 0; j < a[i].size(); j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}