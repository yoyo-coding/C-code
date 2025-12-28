#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,p,tmp = 1;
    cin>>k>>p;
    for(int i = 1;i <= k;i++){
        cout<<tmp<<" ";
        tmp += p;
    }
    return 0;
    
}