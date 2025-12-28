#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,n,m;
    m = 0;
    cin>>n;
    for(int i = 1;i <= n;i += 1){
        cin>>a;
        if(a>m){
            m = a;
        }
    }
    cout<<m;
    return 0;
    
}