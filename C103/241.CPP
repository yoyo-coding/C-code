#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 10005;

int main() {
    int n;
    cin >> n;
    int head[MAX_N];
    int nxt[MAX_N * 2];
    int to[MAX_N * 2];
    int cnt = 0;
    for(int i = 0; i <= n; i++) {
        head[i] = -1;
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        to[cnt] = v;
        nxt[cnt] = head[u];
        head[u] = cnt++;
        to[cnt] = u;
        nxt[cnt] = head[v];
        head[v] = cnt++;
    }
    
    int dist[MAX_N];
    bool vis[MAX_N];
    for(int i = 0; i <= n; i++) {
        dist[i] = -1;
        vis[i] = false;
    }
    
    queue<int> q;
    q.push(1);
    dist[1] = 1;
    vis[1] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for(int e = head[node]; e != -1; e = nxt[e]) {
            int neighbor = to[e];
            if (!vis[neighbor]) {
                dist[neighbor] = dist[node] + 1;
                vis[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i];
        if (i != n) cout << " ";
    }
    cout << endl;
    
    return 0;
}