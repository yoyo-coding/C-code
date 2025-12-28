#include<bits/stdc++.h>
using namespace std;
int a[1000];
int n;
int main(){
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i = 1;i < n;i++){
        bool flag = 1;
        for(int j = 1;j <= n-i;j++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
                flag = 0;
            }
        }
        if(flag){
            break;
        }
    }
    for(int i = 1;i <= n;i++){
        cout<<a[i]<<" ";    
    }
    return 0;
    
}