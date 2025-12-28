#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,m;
    cin>>a>>b>>c;
    m = a;
    if(m<b){
        m = b;
    }
    if(m<c){
        m = c;
    }
    cout<<m;
    return 0;
    
}