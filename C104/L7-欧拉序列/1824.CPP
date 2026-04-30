#include<bits/stdc++.h>
using namespace std;
const int N = 1005;

int n;
int adj[N][N];
int deg[N];
int euler[2 * N];
int tI[N], tO[N];
int timer = 0;

void dfs(int u, int parent)
{
    timer++;
    tI[u] = timer;
    euler[timer] = u;
    
    for (int i = 1; i <= deg[u]; i++)
    {
        int v = adj[u][i];
        if (v != parent)
        {
            dfs(v, u);
        }
    }
    
    timer++;
    tO[u] = timer;
    euler[timer] = u;
}

int main()
{
    freopen("euler.in", "r", stdin);
    freopen("euler.out", "w", stdout);
    
    cin >> n;
    
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        adj[u][deg[u]] = v;
        deg[v]++;
        adj[v][deg[v]] = u;
    }
    
    for (int u = 1; u <= n; u++)
    {
        for (int i = 1; i < deg[u]; i++)
        {
            for (int j = i + 1; j <= deg[u]; j++)
            {
                if (adj[u][i] > adj[u][j])
                {
                    int temp = adj[u][i];
                    adj[u][i] = adj[u][j];
                    adj[u][j] = temp;
                }
            }
        }
    }
    
    dfs(1, 0);
    
    for (int i = 1; i <= 2 * n; i++)
    {
        if (i > 1) cout << " ";
        cout << euler[i];
    }
    cout << endl;
    
    for (int i = 1; i <= n; i++)
    {
        if (i > 1) cout << " ";
        cout << tI[i];
    }
    cout << endl;
    
    for (int i = 1; i <= n; i++)
    {
        if (i > 1) cout << " ";
        cout << tO[i];
    }
    cout << endl;
    
    return 0;
}
