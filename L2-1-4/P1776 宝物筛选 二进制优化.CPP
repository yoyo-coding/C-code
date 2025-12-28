#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,v;
int value[N],weight[N],dp[N];
int main() {
    cin>>n>>v;
    int vi,wi,mi,cnt = 0;
    for(int i = 1;i <= n;i++){
        cin>>vi>>wi>>mi;
        int k = 1;
        while(k <= mi){
            value[++cnt] = vi * k;
            weight[cnt] = wi * k;
            mi -= k;
            k *= 2;
        }
        if(mi > 0){
            value[++cnt] = vi * mi;
            weight[cnt] = wi * mi;
        }
    }
    for(int i = 1;i <= cnt;i++){
        for(int j = v;j >= weight[i];j--){
            dp[j] = max(dp[j],dp[j - weight[i]] + value[i]);
        }
    }
    cout<<dp[v];
    return 0;
}