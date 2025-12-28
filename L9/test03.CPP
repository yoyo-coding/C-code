#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b = 0,n;
    cin>>n;
    for(int i = 1;i <= n;i += 1){
        cin>>a;
        b += a;
    }
    
    cout<<b;
    return 0;
    
}