#pragma GCC optimize("O2")

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 2; i <= n; i++) {
        a[i] = min(a[i], 2 * a[i-1]);
    }
    
    while (q--) {
        ll x;
        cin >> x;
        
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        unordered_map<ll, ll> dist;
        
        pq.push({0, 0});
        dist[0] = 0;
        
        ll res = LLONG_MAX;
        
        while (!pq.empty()) {
            auto [c, b] = pq.top();
            pq.pop();
            if (c >= res) break;
            
            if (dist[b] < c) continue;
            
            if (b >= x) {
                res = min(res, c);
                continue;
            }
            
            for (int i = 1; i <= n; i++) {
                ll nb = b + (1LL << (i - 1));
                ll nc = c + a[i];
                
                if (nc >= res) continue;
                
                if (!dist.count(nb) || nc < dist[nb]) {
                    dist[nb] = nc;
                    pq.push({nc, nb});
                }
            }
        }
        
        cout << res << "\n";
    }
    
    return 0;
}