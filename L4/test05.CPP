#include<bits/stdc++.h>
using namespace std;
int main(){
    char a,b;
    cin>>a>>b;
    if(b-a == 1){
        cout<<"Yes";
    }
    if(a-b == 1){
        cout<<"Yes";
    }
    if(b-a > 1){
        cout<<"No";
    }
    if(a-b > 1){
        cout<<"No";
    }
    
    
    return 0;
    
}