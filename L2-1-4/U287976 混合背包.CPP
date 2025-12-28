#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, v;
int value[N], weight[N], dp[N];
int main() {
    cin >> v >> n;
    int vi, wi, mi, cnt = 0;
    for(int i = 1; i <= n; i++){
        cin >> wi >> vi >> mi;
        if(mi == 0) {
            for(int j = wi; j <= v; j++) {
                dp[j] = max(dp[j], dp[j - wi] + vi);
            }
        }else{
            int k = 1;
            while(k <= mi){
                weight[++cnt] = wi * k;
                value[cnt] = vi * k;
                mi -= k;
                k *= 2;
            }
            if(mi > 0){
                weight[++cnt] = wi * mi;
                value[cnt] = vi * mi;
            }
        }
    }
    for(int i = 1; i <= cnt; i++){
        for(int j = v; j >= weight[i]; j--){
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout<<dp[v];
    return 0;
}