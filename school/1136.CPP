#include<bits/stdc++.h>
using namespace std;
int main() {
    double a[10];
    int x;
    
    for(int i = 0;i < 10;i++){
        cin>>a[i];
    }
    cin>>x;
    for(int i = 0;i < 10;i++){
        a[i] = a[i] / x;
    }

    for(int i = 0;i < 10;i++){
        cout<<fixed<<setprecision(4)<<a[i]<<" ";
    }
    return 0;
}