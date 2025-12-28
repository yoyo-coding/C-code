#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n, k;
    cin >> n >> k;
    ll pyramid[101][101];
    ll dp[101][101][201];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int t = 0; t <= k; t++) {
                dp[i][j][t] = LLONG_MIN;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> pyramid[i][j];
        }
    }
    dp[1][1][0] = pyramid[1][1];
    if (k > 0) {
        dp[1][1][1] = pyramid[1][1] * 3; 
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int t = 0; t <= k; t++) {
                if (j > 1) {
                    if (t <= k) {
                        dp[i][j][t] = max(dp[i][j][t], dp[i-1][j-1][t] + pyramid[i][j]);
                    }
                    if (t > 0) {
                        dp[i][j][t] = max(dp[i][j][t], dp[i-1][j-1][t-1] + pyramid[i][j] * 3);
                    }
                }
                if (j <= i - 1) {
                    if (t <= k) {
                        dp[i][j][t] = max(dp[i][j][t], dp[i-1][j][t] + pyramid[i][j]);
                    }
                    if (t > 0) {
                        dp[i][j][t] = max(dp[i][j][t], dp[i-1][j][t-1] + pyramid[i][j] * 3);
                    }
                }
            }
        }
    }
    ll result = LLONG_MIN;
    for (int j = 1; j <= n; j++) {
        for (int t = 0; t <= k; t++) {
            result = max(result, dp[n][j][t]);
        }
    }
    cout << result << endl;
    
    return 0;
}