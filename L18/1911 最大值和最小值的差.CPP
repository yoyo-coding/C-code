#include<bits/stdc++.h>
using namespace std;
int mina = INT_MAX;
int maxa = 0;
int maxn(int a){
    
    if(a >= maxa){
        maxa = a;
    }
    return maxa;
}
int minn(int a){
    
    if(a <= mina){
        mina = a;
    }
    return mina;
}
int main(){
    int m,a,maxnum,minnum;
    cin>>m;
    for(int i = 0;i < m;i++){
        cin>>a;
        maxnum = maxn(a);
        minnum= minn(a);
    }
    cout<<maxnum-minnum;
    return 0;
    
}