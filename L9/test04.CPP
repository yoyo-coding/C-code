#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,m;
    m = 0;
    for(int i = 1;i <= 5;i += 1){
        cin>>a;
        if(a>m){
            m = a;
        }
    }
    cout<<m;
    return 0;
    
}