#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[105][105] = {},b[105][105] = {};
    int p,n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p = a[i][j] + b[i][j];
            cout<<p<<" ";
        }
        cout<<endl;
    }
    return 0;
    
}