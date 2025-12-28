#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a[105][105] = {},b[105][105] = {};
    cin>>n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = a[j][i];
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
    
}