#include<bits/stdc++.h>
using namespace std;
int a,b;
bool isPrime(int x){
    if(x < 2){
        return false;
    }
    for(int i = 2;i <= sqrt(x);i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
int main() {
    cin>>a>>b;
    for(int i = a;i < b;i++){
        int p = 0;
        int i1 = i,i2 = i;
        while(i1){
            p = p * 10 + i1 % 10;
            i1 /= 10;
        }
        if(isPrime(p) && isPrime(i2)){
            cout<<i<<endl;
        }
    }
    
    return 0;
}