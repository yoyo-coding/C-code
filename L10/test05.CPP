#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b = 0;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a;
        if(a%2 == 0){
            b++;
        }
    }
    cout<<b<<endl;
    if(n == b){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    return 0;
    
}