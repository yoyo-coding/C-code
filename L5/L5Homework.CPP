#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a;
    if(a>2){
        b = 6+(a-2)*2
    }
    else{
        b = 6
    }
    cout<<b;
    
    //-------我是分割线-------

    int n;
    cin>>n;
    if(n <= 5){
        cout<<"computer";
    }
    else if(n > 5 and n <= 10){
        cout<<"luggage";
    }
    else{
        cout<<"coupon";
    }

    //-------我是分割线-------

    int s;
    cin>>s;
    if(s>=80){
        cout<<"A";
    }
    else if(s<80 and a>=60){
        cout<<"B";
    }
    else{
        cout<<"C";
    }

    }