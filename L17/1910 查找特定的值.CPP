#include<bits/stdc++.h>
using namespace std;
int a[10005];
int n;
int find(int t){
    for(int i = 1;i <= n;i++){
        if(a[i] == t){
            return i;
        }
    }
    return -1;
}
int main(){
    int t;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    cin>>t;
    cout<<find(t);
    return 0;
    
}