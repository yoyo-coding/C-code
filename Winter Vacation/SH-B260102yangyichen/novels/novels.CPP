#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 100005;
ll a[N];
ll n,m;

bool chk(ll x) {
    ll days = 0;
    ll cur = 0;
    
    for(ll i = 0;i < m;i++) {
        if(cur + a[i] >= x) {
            days++;
            cur = (cur + a[i]) / 2;
        } else {
            cur += a[i];
        }
    }
    
    if(cur > 0 && cur < x) days++;
    return days <= n;
}

int main() {
    freopen("novels.in","r",stdin);
    freopen("novels.out","w",stdout);
    
    cin>>n>>m;
    
    ll sum = 0;
    for(ll i = 0;i < m;i++) {
        cin>>a[i];
        sum += a[i];
    }
    
    ll l = 1, r = sum;
    ll ans = 0;
    
    while(l <= r) {
        ll mid = (l+r)/2;
        if(chk(mid)) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    
    cout<<ans;
    return 0;
}