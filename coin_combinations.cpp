#include<bits/stdc++.h>
using namespace std;
const int MAXM = 100005;
const int MAXN = 105;
bool dp[MAXM];
int main() {
    int n, m;
    while(cin >> n >> m && (n != 0 || m != 0)) {
        int a[MAXN], c[MAXN];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> c[i];
        }
        
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for(int i = 0; i < n; i++) {
            int face_value = a[i];
            int count = c[i];
            for(int k = 1; k <= count; k <<= 1) {
                int val = k * face_value;
                for(int j = m; j >= val; j--) {
                    if(dp[j - val]) {
                        dp[j] = true;
                    }
                }
                count -= k;
            }
            if(count > 0) {
                int val = count * face_value;
                for(int j = m; j >= val; j--) {
                    if(dp[j - val]) {
                        dp[j] = true;
                    }
                }
            }
        }
        int result = 0;
        for(int i = 1; i <= m; i++) {
            if(dp[i]) {
                result++;
            }
        }
        
        cout << result << endl;
    }
    
    return 0;
}