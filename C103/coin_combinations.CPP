#include<bits/stdc++.h>
using namespace std;

const int MAXM = 100005;
int n, m;
int a[105], c[105];
bool dp[MAXM]; // dp[i] 表示是否能组成价值i

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == 0 && m == 0) break;
        
        // 读入硬币面额和数量
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
        
        // 初始化dp数组
        memset(dp, false, sizeof(dp));
        dp[0] = true; // 价值0总是可以组成的（不选任何硬币）
        
        // 对每种硬币进行处理
        for (int i = 1; i <= n; i++) {
            // 使用二进制优化处理多重背包
            for (int k = 1; k <= c[i]; k <<= 1) {
                // 从大到小更新dp数组，避免重复使用
                for (int j = m; j >= k * a[i]; j--) {
                    if (dp[j - k * a[i]]) {
                        dp[j] = true;
                    }
                }
                c[i] -= k;
            }
            
            // 处理剩余的硬币
            if (c[i] > 0) {
                for (int j = m; j >= c[i] * a[i]; j--) {
                    if (dp[j - c[i] * a[i]]) {
                        dp[j] = true;
                    }
                }
            }
        }
        
        // 统计能组成的总价值种类数
        int ans = 0;
        for (int i = 0; i <= m; i++) {
            if (dp[i]) ans++;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}