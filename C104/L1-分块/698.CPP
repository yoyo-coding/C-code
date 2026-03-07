#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 100005;
const ll M = 100000007;
ll n,m,l,a[N],b[N],bs[N];
void add(ll x,ll y){
    a[x] = (a[x]+y)%M;
    bs[b[x]] = (bs[b[x]]+y)%M;
}
ll rsq(ll l,ll r){
    ll s = 0;
    if(b[l] == b[r]){
        for(int i = l;i <= r;i++){
            s = (s+a[i])%M;
        }
    }
    else{
        for(int i = l;b[i] == b[l];i++){
            s = (s+a[i])%M;
        }
        for(int i = b[l]+1;i < b[r];i++){
            s = (s+bs[i])%M;
        }
        for(int i = r;b[i] == b[r];i--){
            s = (s+a[i])%M;
        }
    }
    return s;
}
int main() {
    cin>>n>>m;
    l = sqrt(n);
    for(ll i = 1;i <= n;i++){
        b[i] = (i-1)/l+1;
    }
    for(ll i = 1;i <= m;i++){
        ll t,x,y;
        cin>>t>>x>>y;
        if(t == 2){
            add(x,y);
        }
        else{
            cout<<rsq(x,y)<<endl;
        }
    }
    return 0;
}