#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
    int n;
    cin>>n;
    a[1] = 1;
    for(int i = 2;i <= n;i++){
        a[i] = a[i-1] + i * i;
    }
    cout<<a[n];
    return 0;
    
}