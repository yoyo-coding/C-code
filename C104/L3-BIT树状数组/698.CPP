#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 100000007;
const int MAXN = 100010;
ll n, m;
ll bit[MAXN];

ll lsb(ll i){
    return i & (-i);
}

void add(ll i, ll z){
    while(i <= n){
        bit[i] += z;
        i += lsb(i);
    }
}

ll psq(ll i){
    ll sum = 0;
    while(i){
        sum = (sum + bit[i]) % MOD;
        i -= lsb(i);
    }
    return sum;
}

int main() {
    cin >> n >> m;
    
    for(ll i = 1; i <= m; i++){
        ll t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            ll ans = (psq(y) - psq(x-1) + MOD) % MOD;
            cout << ans << endl;
        } else {
            add(x, y);
        }
    }
    
    return 0;
}