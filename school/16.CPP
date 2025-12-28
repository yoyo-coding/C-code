#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,max = 0;
    for(int i = 1;i <= 3;i++){
        cin>>n;
        if(n >= max){
            max = n;
        }
    }
    cout<<max;
    return 0;
}