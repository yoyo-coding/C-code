#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int main(){
    int n,k,a[N] = {};
    cin>>n>>k;
    for(int i = 1;i <= n;i++){
        if(i % k != 0){
            a[i] = 1;
        }
    }
    for(int i = 1;i <= n;i++){
        if(a[i]){
            cout<<i<<" ";
        }
    }    
    return 0;
    
}