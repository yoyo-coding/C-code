#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int n,m;
int value[N],weight[N],num[N],dp[N];
int main() {
    cin>>n>>m;
    for(int i = 0;i < n;i++){
        cin>>value[i]>>weight[i]>>num[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= weight[i-1];j--){
            for(int k = 0;k <= num[i-1] && k * weight[i-1] <= j;k++){
                dp[j] = max(dp[j],dp[j - k * value[i-1]] + k * weight[i-1]);
            }
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}
