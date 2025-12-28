#include<bits/stdc++.h>
using namespace std;
string a;
int b,x = 0;
int na[1000],ns[1000];
int lena;
int main(){
    cin>>a>>b;
    lena = a.size();
    for(int i = 0;i < lena;i++){
        na[lena-i] = a[i]-'0'; 
    }
    for(int i = 1;i <= lena;i++){
        ns[i] = na[i] * b + x;
        x = ns[i] / 10;
        ns[i] %= 10;
    }
    while(x){
        ns[++lena] = x % 10;
        x /= 10;
    }
    for(int i = lena;i >= 1;i--){
        cout<<ns[i];
    }
}