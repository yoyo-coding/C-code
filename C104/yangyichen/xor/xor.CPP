#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 200005;
int k, q;
int x[MAXN];
int p[MAXN];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    
    cin>>k;
    
    for (int i = 1; i <= k; i++) {
        cin>>x[i];
    }
    
    for (int i = k + 1; i <= 2 * (k + 1); i++) {
        x[i] = 0;
        for (int j = 1; j <= k; j++) {
            x[i] ^= x[i - j];
        }
    }
    
    for (int i = 1; i <= 2 * (k + 1); i++) {
        p[i] = p[i - 1] ^ x[i];
    }
    
    int cycle = 2 * (k + 1);
    int cycle_xor = p[cycle];
    
    cin>>q;
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin>>l>>r;
        
        int l_in = (l - 1) % cycle + 1;
        int r_in = (r - 1) % cycle + 1;
        int l_blk = (l - 1) / cycle;
        int r_blk = (r - 1) / cycle;
        
        int ans = 0;
        
        if (l_blk == r_blk) {
            ans = p[r_in] ^ p[l_in - 1];
        } else {
            ans = p[cycle] ^ p[l_in - 1];
            int mid = r_blk - l_blk - 1;
            if (mid % 2 == 1) {
                ans ^= cycle_xor;
            }
            ans ^= p[r_in];
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}