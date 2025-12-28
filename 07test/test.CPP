#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e,f,g,i;
    cin>>a;
    i = 0;
    b = a%10;
    c = a%100/10;
    d = a%1000/100;
    e = a%10000/1000;
    f = a%100000/10000;
    g = a%1000000/100000;
    if(b == 8)i++; 
    if(c == 8)i++;
    if(d == 8)i++;
    if(e == 8)i++;
    if(f == 8)i++;
    if(g == 8)i++;
    cout<<i;
    if(i == 6)cout<<"first prize";
    else if(i == 5)cout<<"second prize";
    else if(i >=3 )cout<<"third prize";
    else cout<<"thank you";
    return 0;
    
}