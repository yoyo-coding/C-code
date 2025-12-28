#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[1005];
    int n,max = -1,maxn = 0;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    for(int i = 0 ; i < n ; i++){
        if(a[i] > max){
            max = a[i];
            maxn = i;
        }
    }
    cout<<maxn+1;
    
    return 0;
}