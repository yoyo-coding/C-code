#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 150005;
const int MAXM = 300005;
const ll INF = 1e18;

int h[MAXN], nxt[MAXM], to[MAXM], w[MAXM], cnt = 0;
ll d[MAXN];
bool vst[MAXN];
int n, m;

struct p {
    int id;
    ll dist;
    bool operator<(const p& other) const {
        return dist > other.dist;
    }
};

void add_edge(int u, int v, int weight) {
    to[cnt] = v;
    w[cnt] = weight;
    nxt[cnt] = h[u];
    h[u] = cnt++;
}

void dijkstra(int start) {
    for(int i = 1; i <= n; i++) {
        d[i] = INF;
        vst[i] = false;
    }
    d[start] = 0;
    
    priority_queue<p> pq;
    pq.push({start, 0});
    
    while(!pq.empty()) {
        p cur = pq.top();
        pq.pop();
        
        int u = cur.id;
        if(vst[u]) continue;
        vst[u] = true;
        
        for(int e = h[u]; e != -1; e = nxt[e]) {
            int v = to[e];
            int weight = w[e];
            if(d[v] > d[u] + weight) {
                d[v] = d[u] + weight;
                pq.push({v, d[v]});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        h[i] = -1;
    }
    
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        add_edge(x, y, z);
    }
    
    dijkstra(1);
    
    if(d[n] == INF) {
        cout << -1 << endl;
    } else {
        cout << d[n] << endl;
    }
    
    return 0;
}