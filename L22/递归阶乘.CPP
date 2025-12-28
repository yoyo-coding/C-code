#include<bits/stdc++.h>
using namespace std;
long long f(long long a){
    if(a == 1){
        return 1;
    }
    return f(a-1)*a;
}
int main(){
    long long a;
    cin>>a;
    cout<<f(a);
    return 0;
    
}