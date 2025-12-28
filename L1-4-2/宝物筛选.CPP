#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;     // 宝物最多种数
const int MAXW = 40005;   // 最大重量

int n, W;
int v[MAXN], w[MAXN], m[MAXN];
int dp[MAXW];

int main() {
    // 输入宝物种数和采集车最大载重
    cin >> n >> W;
    
    // 输入每种宝物的信息
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i] >> m[i];
    }
    
    // 多重背包优化解法
    for (int i = 1; i <= n; i++) {
        // 使用二进制优化
        for (int k = 1; k <= m[i]; k <<= 1) {
            for (int j = W; j >= k * w[i]; j--) {
                dp[j] = max(dp[j], dp[j - k * w[i]] + k * v[i]);
            }
            m[i] -= k;
        }
        
        // 剩余部分直接处理
        if (m[i] > 0) {
            for (int j = W; j >= m[i] * w[i]; j--) {
                dp[j] = max(dp[j], dp[j - m[i] * w[i]] + m[i] * v[i]);
            }
        }
    }
    
    cout << dp[W] << endl;
    
    return 0;
}