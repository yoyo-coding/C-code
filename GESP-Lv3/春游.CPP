#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m,tmp;
    cin>>n>>m;
    bool a[1005] = {};
    int cnt = 0;
    while (cnt != m){
        cin>>tmp;
        a[tmp] = true;
        cnt++;
    }
    bool flag = 1;
    for(int i = 0 ; i < n ; i++){
        if(a[i] == true){
            continue;
        }
        else if(a[i] == false){
            cout<<i<<" ";
            flag = 0; 
        }
    }
    if(flag == 1){
        cout<<n;
    }
    
    return 0;
}