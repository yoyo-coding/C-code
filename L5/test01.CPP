#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y,a,b,c,d,e;
    cin>>x>>y;
    a = x/100;
    b = y/10;
    c = (x/10)%10;
    d = y%10;
    e = x%10;
    cout<<a<<b<<c<<d<<e;
    return 0;
    
}