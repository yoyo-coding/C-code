#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 5005;
const int INF = 0x3f3f3f3f;
int y[MAXN], dp[MAXN][1005];
int main() {
    freopen("variety.in", "r", stdin);
    freopen("variety.out", "w", stdout);
    
    int n, m;
    cin>>n>>m;
    
    for(int i = 1; i <= n; i++) {
        cin>>y[i];
    }
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = INF;
        }
    }
    
    dp[0][0] = 0;
    
    for(int i = 1; i <= n; i++) {
        dp[i][1] = 0;
        for(int j = 2; j <= m; j++) {
            for(int k = 1; k < i; k++) {
                if(dp[k][j - 1] < INF) {
                    dp[i][j] = min(dp[i][j], dp[k][j - 1] + abs(y[i] - y[k]));
                }
            }
        }
    }
    
    int ans = INF;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, dp[i][m]);
    }
    
    cout<<ans<<endl;
    
    return 0;
}