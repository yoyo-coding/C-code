#include<bits/stdc++.h>
using namespace std;
int a,m;
int v[10005],w[10005];
long long dp[10005];
int main() {
    cin>>a>>m;
    for(int i = 1;i <= m;i++){
        cin>>v[i]>>w[i];
    }
    for(int i = 1;i <= m;i++){
        for(int j = v[i];j <= a;j++){
            dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[a];
    return 0;
}