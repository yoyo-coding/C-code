#include<bits/stdc++.h>
using namespace std;
int jc(int a){
    int tmp = 1;
    for(int i = a;i > 0;i--){
        tmp *= i
    }
    return tmp;
}

int main(){
    int a,res = 0;
    cin>>a;
    for(int i = a;i > 0;i--){
        res += jc(i)
    }
    cout<<res;
    return 0;
    
}