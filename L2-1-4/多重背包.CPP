#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int n,m;
int value[N],weight[N],num[N],dp[N];
int main() {
    freopen("knapsack.in","r",stdin);
    freopen("knapsack.out","w",stdout);
    cin>>n>>m;
    for(int i = 0;i < n;i++){
        cin>>weight[i]>>value[i]>>num[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= weight[i-1];j--){
            for(int k = 0;k <= num[i-1] && k * weight[i-1] <= j;k++){
                dp[j] = max(dp[j], dp[j - k * weight[i-1]] + k * value[i-1]);
            }
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}