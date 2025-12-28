#include<bits/stdc++.h>
using namespace std;
int main() {
    int w,n;
    int a[1000];
    cin>>w>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int cnt = 0;
    int l = 0,r = n-1;
    while(l <= r){
        if(a[l] + a[r] <= w){
            l++;
            r--; 
        }else{
            r--;
        }
        cnt++;
    }
    cout<<cnt;
    return 0;
}