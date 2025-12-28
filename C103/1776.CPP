#include<bits/stdc++.h>
using namespace std;
const int MAX_M = 5005;
struct Edge {
    int u, v, w;
} edges[MAX_M];

int par[101], rnk[101];

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return false;
    if(rnk[x] < rnk[y]) par[x] = y;
    else {
        par[y] = x;
        if(rnk[x] == rnk[y]) rnk[x]++;
    }
    return true;
}

bool cmp(Edge a, Edge b) {
    return a.w > b.w;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }
    sort(edges, edges+m, cmp);
    for(int i=1; i<=n; ++i){
        par[i] = i;
    } 
    int res = 0, cnt = 0;
    for(int i=0; i<m; ++i) {
        if(unite(edges[i].u, edges[i].v)) {
            res += edges[i].w;
            if(cnt++ == n-1) break;
        }
    }
    cout<<res<<endl;
    return 0;
}