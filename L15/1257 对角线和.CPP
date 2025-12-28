#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[55][55] = {};
    int n,z = 0;
    cin>>n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(i == j){
                z+=a[i][j];
            }
        }
    }
    int j = 1;
    for(int i = n;i >= 1;i--){
        z+=a[i][j];
        j++;
    }
    if(n%2 != 0){
        cout<<z-a[(n+1)/2][(n+1)/2];
    }
    else{
        cout<<z;
    }
    return 0;
    
}