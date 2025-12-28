#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int a[100005];
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = n;i > n-3;i--){
        cout<<a[i]<<" ";
    }
    return 0;
}