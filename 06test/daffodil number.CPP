#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a;
    b = a%10;
    c = a%100/10;
    d = a/100;
    if(b*b*b+c*c*c+d*d*d == a){
        cout<<"YES";

    }
    return 0;
    
}