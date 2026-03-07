#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a,b,tmp1,tmp2;
bool isPrime(int x){
    if(x < 2)return false;
    for(int i = 2;i < x;i++){
        if(x%i == 0){
            return false;
        }
    }
    return true;
}
int main() {
    cin>>a>>b;
    for(int i = a;i <= b;i++){
        tmp1 = i;
        tmp2 = i%10*10 + i/10;
        if(isPrime(tmp1) && isPrime(tmp2)){
            cout<<i<<endl;
        }
    }
    return 0;
}