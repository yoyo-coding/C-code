#include<bits/stdc++.h>
using namespace std;
int a[10];
int f(int l,int r){
    if(l == r)
        return a[l];
    int m = (l+r)/2;
    return max(f(l,m),f(m+1,r));
}
int main(){
    int n; 
    cin>>n;
    for(int i = 1 ;i <= n ; i++){
        cin>>a[i];
    }
    cout<<f(1,n);
    return 0;
}