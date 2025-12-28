#include<bits/stdc++.h>
using namespace std;

int main(){
    long long x = 3,y,res = 1;
    cin>>y;
    for(int i = 1;i <= y;i++){
        res *= x; 
    }
    cout<<res;
    return 0;
}