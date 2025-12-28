#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a>b and a>c){
        if(c>b){
            cout<<b<<" "<<c<<" "<<a;
        }
        else{
            cout<<c<<" "<<b<<" "<<a;
        }
    }
    if(b>c and b>a){
        if(a>c){
            cout<<c<<" "<<a<<" "<<b;
        }
        else{
            cout<<a<<" "<<c<<" "<<b;
        }
    }
    if(c>b and c>a){
        if(a>b){
            cout<<b<<" "<<a<<" "<<c;
        }
        else{
            cout<<a<<" "<<b<<" "<<c;
        }
    }
    return 0;
    
}