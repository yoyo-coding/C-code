#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,a = 1,b = 1,c;
    cin>>k;
    cout<<a<<" "<<b<<" ";
    for(int i = 3;i <= k;i++){
        c = a;
        a = b;
        b = c+a;
        cout<<b<<" ";

    }
    return 0;
    
}