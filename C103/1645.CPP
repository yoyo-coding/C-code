#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXM = 2 * MAXN;
int h[MAXN], nxt[MAXM], to[MAXM], cnt = 0;
int p[MAXN], d[MAXN], st_s[MAXN], st_h[MAXN];
int n;

void add_edge(int u, int v) {
    to[cnt] = v;
    nxt[cnt] = h[u];
    h[u] = cnt++;
}
void dfs(int u, int par, int dep) {
    p[u] = par;
    d[u] = dep;
    st_s[u] = 1;
    st_h[u] = 1;
    int max_h = 0;
    for (int i = h[u]; i != -1; i = nxt[i]) {
        int v = to[i];
        if (v != par) {
            dfs(v, u, dep + 1);
            st_s[u] += st_s[v];
            max_h = max(max_h, st_h[v]);
        }
    }
    if (max_h > 0) {
        st_h[u] = max_h + 1;
    }
}

int main() {
    cin>>n;
    for (int i = 1; i <= n; i++) {
        h[i] = -1;
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin>>u>>v;
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 0, 1);
    for (int i = 1; i <= n; i++) {
        cout<<p[i]<<" "<<d[i]<<" "<<st_s[i]<<" "<<st_h[i]<<"\n";
    }
    
    return 0;
}
