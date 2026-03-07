#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 500005;
const int LOGN = 20;
vector<int> G[MAXN];
int fa[MAXN][LOGN];
int depth[MAXN];

void dfs(int u, int p, int d) {
    depth[u] = d;
    fa[u][0] = p;
    
    for (int j = 1; j < LOGN; j++) {
        fa[u][j] = fa[fa[u][j-1]][j-1];
    }
    
    for (int v : G[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }
    
    for (int j = LOGN - 1; j >= 0; j--) {
        if (depth[x] - (1<<j) >= depth[y]) {
            x = fa[x][j];
        }
    }
    
    if (x == y) {
        return x;
    }
    
    for (int j = LOGN - 1; j >= 0; j--) {
        if (fa[x][j] != fa[y][j]) {
            x = fa[x][j];
            y = fa[y][j];
        }
    }
    
    return fa[x][0];
}

int main() {
    int N, M, S;
    cin >> N >> M >> S;
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    dfs(S, S, 0);
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout<<lca(a, b)<<endl;
    }
    
    return 0;
}
