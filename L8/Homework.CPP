#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    
    int a, b, c;
    cin >> a >> b >> c;
    
    char result = "";
    if (n <= 3) {
        if (a <= b && a <= c) {
            result = "library";
        } else if (b <= a && b <= c) {
            result = "comprehensive";
        } else {
            result = "art";
        }
    } else if (n <= 5) {
        if (b <= a && b <= c) {
            result = "comprehensive";
        } else if (a <= b && a <= c) {
            result = "library";
        } else {
            result = "art";
        }
    } else {
        if (c <= a && c <= b) {
            result = "art";
        } else if (a <= b && a <= c) {
            result = "library";
        } else {
            result = "comprehensive";
        }
    }

    cout << result << endl;

    //---------------------

    int a;
    cin>>a;
    if(a == 1){
        cout<<"No"
    }
    else{
        cout<<"Yes";
    }

    //----------------------
    
    int a;
    char b,c,r;
    cin>>a>>b>>c>>r;
    if(b == "a"){
        r = a;
    }
    else if(b == "b"){
        r = a*2;
    }
    else{
        r = a*3;
    }
    if(c == "f"){
        r = r+0;
    }
    else if(c == "m"){
        r = r-3;
    }
    else{
        r = r+10;
    }
    cout<<r;

    //---------------------

    int x;
    cin >> x;
    if(x<10)
        cout << 45*x;
    else if(10<=x&&x<=20)
        cout << (45-2)*x;
    else if(20<x&&x<=30)
        cout << (45-5)*x;
    else 
        cout << (45-10)*x;
    
    return 0;
    
}