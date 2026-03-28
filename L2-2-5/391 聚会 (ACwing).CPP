#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 500000 + 5;
const int LOGN = 20;
int n, m;
vector<int> g[MAXN];
int up[MAXN][LOGN];
int d[MAXN];

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    int diff = d[u] - d[v];
    for (int j = 0; diff; ++j) {
        if (diff & 1) u = up[u][j];
        diff >>= 1;
    }
    if (u == v) return u;
    for (int j = LOGN - 1; j >= 0; --j) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

inline int dist(int u, int v) {
    int w = lca(u, v);
    return d[u] + d[v] - 2 * d[w];
}

int main() {
    if (!(cin >> n >> m)) return 0;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> stk;
    stk.reserve(n);
    stk.push_back(1);
    d[1] = 0;
    up[1][0] = 1;
    for (int i = 1; i < LOGN; i++) up[1][i] = 1;
    vector<int> fa(n + 1, 0);
    fa[1] = 0;
    while (!stk.empty()) {
        int u = stk.back();
        stk.pop_back();
        for (int v : g[u]) {
            if (v == fa[u]) continue;
            fa[v] = u;
            d[v] = d[u] + 1;
            up[v][0] = u;
            for (int k = 1; k < LOGN; k++) {
                up[v][k] = up[ up[v][k-1] ][k-1];
            }
            stk.push_back(v);
        }
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        int x = lca(a, b);
        int y = lca(b, c);
        int z = lca(a, c);
        int p = x;
        int cost = dist(a, x) + dist(b, x) + dist(c, x);
        int cy = dist(a, y) + dist(b, y) + dist(c, y);
        if (cy < cost || (cy == cost && y < p)) {
            cost = cy;
            p = y;
        }
        int cz = dist(a, z) + dist(b, z) + dist(c, z);
        if (cz < cost || (cz == cost && z < p)) {
            cost = cz;
            p = z;
        }
        cout << p << " " << cost << '\n';
    }
    return 0;
}