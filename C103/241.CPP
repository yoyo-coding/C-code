#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> d(n + 1, -1);
    queue<int> q;
    q.push(1);
    d[1] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int nbr : g[node]) {
            if (d[nbr] == -1) {
                d[nbr] = d[node] + 1;
                q.push(nbr);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout<<d[i];
        if (i != n) cout<<" ";
    }
    cout<<endl;
    return 0;
}