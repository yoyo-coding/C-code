#include<bits/stdc++.h>
using namespace std;
int main(){
    //a[j] == 0; ±íÊ¾µÆ¿ªÆô
    int a[5005] = {};
    int n,m,cnt = 0;
    cin>>n>>m;
    for(int i = 1;i <= m;i++){
        for(int l = 1;l <= n;l++){
            if(l % i == 0){
            a[l] = 1-a[l];
            }
        }
    }
    for(int i = 1;i <= n;i++){
        if(a[i] == 0){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
    
}