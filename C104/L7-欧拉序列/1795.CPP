#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 50005;
vector<int> adj[MAXN];
ll sz[MAXN], ds[MAXN];
int n;

void dfs1(int u, int p) {
    sz[u] = 1;
    ds[u] = 0;
    
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        ds[u] += ds[v] + sz[v];
    }
}

void dfs2(int u, int p) {
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p) continue;
        ds[v] = ds[u] - sz[v] + (n - sz[v]);
        dfs2(v, u);
    }
}

int main() {
    freopen("dumpster.in", "r", stdin);
    freopen("dumpster.out", "w", stdout);
    
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs1(1, 0);
    dfs2(1, 0);
    
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (ds[i] > ds[ans]) {
            ans = i;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}