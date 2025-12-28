#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=2,b=3,c=4;
    cout<<(a<b or b>c and a>c)<<endl;
    cout<<((a<b or b>c)and a>c)<<endl; 

    bool x = true,y = true, z = false;
    cout<<(!x or y)<<endl;
    cout<<(x or y and z)<<endl;
    cout<<(x or !y and z)<<endl;
    cout<<(x and(y or !z))<<endl;
    return 0;
    
}