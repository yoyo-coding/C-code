#include<bits/stdc++.h>
using namespace std;

const int N = 200000 + 5;
const int B = 600;

int n, m, sz, cnt;
int a[N], bel[N], blk[B];

int query(int l, int r) {
    int res = 0;
    if (bel[l] == bel[r]) {
        for (int i = l; i <= r; ++i) res = max(res, a[i]);
        return res;
    }
    for (int i = l; i <= bel[l] * sz; ++i) res = max(res, a[i]);
    for (int b = bel[l] + 1; b < bel[r]; ++b) res = max(res, blk[b]);
    for (int i = (bel[r] - 1) * sz + 1; i <= r; ++i) res = max(res, a[i]);
    return res;
}

void update(int idx, int val) {
    a[idx] = val;
    int b = bel[idx];
    int l = (b - 1) * sz + 1;
    int r = min(b * sz, n);
    int mx = 0;
    for (int i = l; i <= r; ++i) mx = max(mx, a[i]);
    blk[b] = mx;
}

int main() {
    if (!(cin>>n>>m)) return 0;
    sz = max(1, (int)sqrt(n));
    cnt = (n + sz - 1) / sz;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        bel[i] = (i - 1) / sz + 1;
    }
    for (int i = 1; i <= n; ++i) blk[bel[i]] = max(blk[bel[i]], a[i]);

    vector<int> out;
    for (int k = 0; k < m; ++k) {
        char op;
        int A, Bv;
        cin>>op>>A>>Bv;
        if (op == 'Q') {
            if (A > Bv) swap(A, Bv);
            out.push_back(query(A, Bv));
        } else if (op == 'U') {
            update(A, Bv);
        }
    }

    for (size_t i = 0; i < out.size(); ++i) {
        if (i) cout<<' ';
        cout<<out[i];
    }
    return 0;
}
