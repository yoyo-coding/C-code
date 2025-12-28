#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n >= 100){
        cout<<n*7;
    }
    else if(n >= 50){
        cout<<n*8;
    }
    else{
        cout<<n*10;
    }
    return 0;
    
}