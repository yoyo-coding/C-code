#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1005;
vector<int> g[N];
int d[N];
int l[N];
bool s[N][N];

int main() {
    freopen("level.in", "r", stdin);
    freopen("level.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i <= 1000; i++) {
        for(int j = 0; j <= 1000; j++) {
            s[i][j] = false;
        }
    }
    
    for(int i = 1; i <= m; i++) {
        int sz;
        cin >> sz;
        vector<int> st(sz);
        for(int j = 0; j < sz; j++) {
            cin >> st[j];
            s[i][st[j]] = true;
        }
        
        vector<int> ns;
        for(int j = st[0]; j <= st.back(); j++) {
            if(!s[i][j]) {
                ns.push_back(j);
            }
        }
        
        for(int k = 0; k < ns.size(); k++) {
            int u = ns[k];
            for(int p = 0; p < st.size(); p++) {
                int v = st[p];
                g[u].push_back(v);
                d[v]++;
            }
        }
    }
    
    queue<int> q;
    
    for(int i = 0; i <= 1000; i++) {
        l[i] = 0;
    }
    
    for(int i = 1; i <= n; i++) {
        if(d[i] == 0) {
            q.push(i);
            l[i] = 1;
        }
    }
    
    int ans = 0;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ans = max(ans, l[u]);
        
        for(int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            d[v]--;
            l[v] = max(l[v], l[u] + 1);
            if(d[v] == 0) {
                q.push(v);
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}