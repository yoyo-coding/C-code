#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,i;
    cin>>n>>m;
    i = 5*n;
    if(m > 10*i){
        cout<<m/i;
    }
    else{
        cout<<"no";
    }
    return 0;
    
}