#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,q,l,r;
int a[100005];
int main() {
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    cin>>q;
    for(int i = 1;i <= q;i++){
        cin>>l>>r;
        sort(a+l,a+r);
    }
    for(int i = 0;i < n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}