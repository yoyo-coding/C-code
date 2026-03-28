#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 100005;
const int MOD = 100000007;

int n, m;
int a[MAXN];
int tag[MAXN];
int bl[MAXN];
int L[MAXN], R[MAXN];
int block_size;
int block_num;

void add(int x, int y, int z) {
    for (int i = x; i <= min(y, R[bl[x]]); i++) {
        a[i] = (a[i] + z) % MOD;
    }
    
    if (bl[x] != bl[y]) {
        for (int i = L[bl[y]]; i <= y; i++) {
            a[i] = (a[i] + z) % MOD;
        }
        for (int i = bl[x] + 1; i <= bl[y] - 1; i++) {
            tag[i] = (tag[i] + z) % MOD;
        }
    }
}

int query(int x) {
    return (a[x] + tag[bl[x]]) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    block_size = sqrt(n);
    block_num = (n + block_size - 1) / block_size;
    
    for (int i = 1; i <= n; i++) {
        bl[i] = (i - 1) / block_size + 1;
    }
    
    for (int i = 1; i <= block_num; i++) {
        L[i] = (i - 1) * block_size + 1;
        R[i] = i * block_size;
    }
    R[block_num] = n;
    
    while (m--) {
        int t, x, y, z;
        cin >> t >> x >> y >> z;
        
        if (t == 1) {
            add(x, y, z);
        } else {
            cout << query(x) << endl;
        }
    }
    
    return 0;
}