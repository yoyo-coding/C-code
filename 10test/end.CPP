#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,j = 0,o = 0;
    cin>>n;
    for(int i = 0;i <= n;i++){
        if(i%2 == 0){
            o+=i;
        }
        if(i%2 == 1){
            j+=i;
        }
    }
    cout<<o<<" "<<j;
    return 0;
    
}