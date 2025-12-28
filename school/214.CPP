#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int max = -10005,maxn;
    int a[1005];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] >= max){
            max = a[i];
            maxn = i;
        }
    }
    for(int i = 0; i < n; i++){
        
    }
    return 0;
}