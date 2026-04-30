#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2005;
const int MAXM = 205;
int dp[MAXN][MAXM][2];

int main() {
    freopen("missile3.in","r",stdin);
    freopen("missile3.out","w",stdout);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j][0] = dp[i][j][1] = -1e9;
        }
    }
    
    dp[0][0][0] = 0;
    
    for(int i = 0; i < n; i++) {
        char missile = s[i];
        for(int j = 0; j <= m; j++) {
            for(int d = 0; d < 2; d++) {
                if(dp[i][j][d] < 0) continue;
                
                int can_intercept = (d == 0 && missile == 'F') || (d == 1 && missile == 'B');
                dp[i + 1][j][d] = max(dp[i + 1][j][d], dp[i][j][d] + can_intercept);
                
                if(j < m) {
                    int nd = 1 - d;
                    can_intercept = (nd == 0 && missile == 'F') || (nd == 1 && missile == 'B');
                    dp[i + 1][j + 1][nd] = max(dp[i + 1][j + 1][nd], dp[i][j][d] + can_intercept);
                }
            }
        }
    }
    
    int ans = 0;
    for(int j = 0; j <= m; j++) {
        for(int d = 0; d < 2; d++) {
            ans = max(ans, dp[n][j][d]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}