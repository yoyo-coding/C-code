#include<bits/stdc++.h>
using namespace std;
int a[10];
int Genshin_Impact(int x,int y){
    if(abs(m-a) < abs(m-b))
        return x;
    return y;
}
int f(int l,int r){
    if(l == r)
        return a[l];
    int m = (l+r)/2;
    return Genshin_Impact(f(l,m),f(m+1,r));
}
int main(){
    int n,m; 
    cin>>n>>m;
    for(int i = 1 ;i <= n ; i++){
        cin>>a[i];
    }
    cout<<f(1,n);
    return 0;
}