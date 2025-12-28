#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b = 1,s = 1;
    cin>>a;
    while(b <= a){
        b*=2;
        s+=1;
    }
    cout<<s;
    return 0;
    
}