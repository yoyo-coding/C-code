#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int value[N], weight[N],num[N], dp[N][N];
int n,w;
int main() {
    cin>>n>>w;
    for(int i = 1; i <= n; i++){
        cin>>value[i]>>weight[i]>>num[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1;j <= w;j++){
            for(int k = 0;k <= num[i] && k*weight[i] <= j;k++){
                dp[i][j] = max(dp[i][j],dp[i-1][j-k*weight[i]+k*value[i]]);
            }
        }
    }
    cout<<dp[n][w]<<endl;
    return 0;
}