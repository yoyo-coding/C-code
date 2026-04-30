#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 100000000;

int n, m;
int f[15][1<<12];
int ptn[1<<12], nOK;

bool check(int s) {
    return (s & (s<<1)) == 0;
}

void init() {
    nOK = 0;
    for(int i = 0; i < (1<<m); i++) {
        if(check(i)) {
            ptn[nOK++] = i;
        }
    }
}

int main() {
    freopen("plan1.in", "r", stdin);
    freopen("plan1.out", "w", stdout);
    
    cin>>n>>m;
    
    init();
    
    for(int i = 0; i < nOK; i++) {
        f[1][ptn[i]] = 1;
    }
    
    for(int i = 2; i <= n; i++) {
        for(int u = 0; u < nOK; u++) {
            int p = ptn[u];
            for(int v = 0; v < nOK; v++) {
                int q = ptn[v];
                if(p & q) continue;
                f[i][p] = (f[i][p] + f[i - 1][q]) % MOD;
            }
        }
    }
    
    int ans = 0;
    for(int p = 0; p < nOK; p++) {
        ans = (ans + f[n][ptn[p]]) % MOD;
    }
    
    cout<<ans<<endl;
    
    return 0;
}
