 #include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1000007;
const int MAXN = 105;
const int MAXM = 105;

int n, m;
int a[MAXN];
int dp[MAXN][MAXM];

int main() {
    freopen("flower.in", "r", stdin);
    freopen("flower.out", "w", stdout);
    
    cin>>n>>m;
    
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= a[i] && k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
            }
        }
    }
    
    cout<<dp[n][m]<<endl;
    
    return 0;
}