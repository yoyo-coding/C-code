#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,cnt = 0;
    int a[80005];
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(a[i] > a[j]){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}