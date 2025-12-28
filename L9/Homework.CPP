#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    for(int i = a;i <= b;i++){
        cout<<i<<" ";
    }
    
    //--------------

    int a,m;
    m = 0;
    for(int i = 1;i <= 5;i += 1){
        cin>>a;
        if(a>m){
            m = a;
        }
    }
    cout<<m;

    //--------------
    
    int a,m;
    m = 0;
    for(int i = 1;i <= 5;i += 1){
        cin>>a;
        if(a<m){
            m = a;
        }
    }
    cout<<m;

    //--------------

    int a,m;
    m = 0;
    for(int i = 1;i <= 5;i += 1){
        cin>>a;
        if(a>m){
            m = a;
        }
    }
    int a,d;
    m = 0;
    for(int i = 1;i <= 5;i += 1){
        cin>>a;
        if(a<m){
            d = a;
        }
    }
    cout<<m-d;
    
    return 0;
    
}