#include<bits/stdc++.h>
using namespace std;
long long pow(long long a,long long b,long long p){
    int ans = 1;
    while(b){
        if(b&1){
            ans = ans*a%p;
        }
        a = a*a%p;
        b >>= 1;
    }
    return ans;
}
int main(){
    long long a,b,p;
    cin>>a>>b>>p;
    cout<<pow(a,b,p)<<endl;
    return 0;
}