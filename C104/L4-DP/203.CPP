#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
string s;
ll num[15][15];
ll dp[15][10];

int main() {
    cin >> n >> k >> s;
    
    for (int i = 0; i < n; i++) {
        ll temp = 0;
        for (int j = i; j < n; j++) {
            temp = temp * 10 + (s[j] - '0');
            num[i + 1][j + 1] = temp;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        dp[i][0] = num[1][i];
    }
    
    for (int j = 1; j <= k; j++) {
        for (int i = j + 1; i <= n; i++) {
            for (int p = j; p < i; p++) {
                dp[i][j] = max(dp[i][j], dp[p][j - 1] * num[p + 1][i]);
            }
        }
    }
    
    cout << dp[n][k] << endl;
    
    return 0;
}