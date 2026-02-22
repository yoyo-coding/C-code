#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 100005;

struct node {
    int p, d, id;
    bool operator<(const node& o) const {
        if (p != o.p) return p < o.p;
        return d > o.d;
    }
};

int n, a[N], b[N];
vector<node> pt;
vector<int> cd;

void dc() {
    sort(cd.begin(), cd.end());
    cd.erase(unique(cd.begin(), cd.end()), cd.end());
}

int gid(int x) {
    return lower_bound(cd.begin(), cd.end(), x) - cd.begin();
}

ll cal(int s) {
    vector<int> df(cd.size() + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        int l = gid(a[i]), r = gid(b[i]);
        df[l] += 1;
        df[r] -= 1;
    }
    
    ll res = 0, cur = 0;
    
    for (int i = 0; i < (int)cd.size() - 1; i++) {
        cur += df[i];
        if (cur > 0) {
            res += (ll)(cd[i + 1] - cd[i]);
        }
    }
    
    return res;
}

int main() {
    freopen("duty.in", "r", stdin);
    freopen("duty.out", "w", stdout);
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        cd.push_back(a[i]);
        cd.push_back(b[i]);
    }
    
    dc();
    
    ll ans = 0;
    
    for (int i = 1; i <= n; i++) {
        ll t = cal(i);
        ans = max(ans, t);
    }
    
    printf("%lld\n", ans);
    
    return 0;
}