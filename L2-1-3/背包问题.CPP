#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int v[1005],w[1005];
int a,b;
int main() {
    cin>>a>>b;
    for(int i = 0;i < a;i++){
        cin>>w[i]>>v[i];
    }
    for(int i = 1;i <= a;i++){
        for(int j = 0;j <= b;j++){
            if(j>=w[i-1]){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[a][b];
    return 0;
}