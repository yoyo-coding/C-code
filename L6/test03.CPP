#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a<b+c and b<a+c and c<a+b){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    return 0;
    
}