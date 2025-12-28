#include<bits/stdc++.h>
using namespace std;
int main(){
    double a;
    int b,c,d,e;
    cin>>a;
    a = a*10;
    b = int(a)%10;
    c = int(a)%100/10;
    d = int(a)/100%10;
    e = int(a)/1000;
    a=(b*1000+c*100+d*10+e)/1000.0;
    cout<<a;
    return 0;
    
}