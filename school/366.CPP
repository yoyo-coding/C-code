#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,cnt = 0;
    int a[100000] = {};
    cin>>n;
    for(int i = 0; i < n;i++){
        cin>>a[i];
        if(a[i]+30 >= 105){
            cnt++;
        }
    }
    
    cout<<cnt;
    
    
    return 0;
}