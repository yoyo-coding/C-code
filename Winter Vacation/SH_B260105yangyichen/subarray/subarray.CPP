#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 100005;
ll a[N];

int main() {
    int n;
    ll x;
    cin>>n>>x;
    
    ll s = 0;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        s += a[i];
    }
    
    if(s % x == 0) {
        cout<<"0"<<endl;
        return 0;
    }
    
    unordered_map<ll, int> p;
    p[0] = 0;
    
    ll ps = 0;
    int ans = n + 1;
    
    for(int i = 1; i <= n; i++) {
        ps += a[i];
        ll r = ((ps % x) + x) % x;
        
        ll t = ((ps - s) % x + x) % x;
        
        if(p.find(t) != p.end()) {
            ans = min(ans, i - p[t]);
        }
        
        if(p.find(r) == p.end()) {
            p[r] = i;
        }
    }
    
    if(ans > n) {
        cout<<"-1"<<endl;
    } else {
        cout<<ans<<endl;
    }
    
    return 0;
}