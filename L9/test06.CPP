#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = 0,b = 0;
    for(int i = 0;i <= 100;i += 2){
        a += i;
    }
    for(int d = 1;d <= 100;d += 2){
        b += d;
    }
    cout<<a<<" "<<b;
    return 0;
    
}