#include<bits/stdc++.h>
using namespace std;
int dp[10005][10005];
int v[10005],w[10005];
int c,h;
int main() {
    cin>>c>>h;
    for(int i = 0;i < h;i++){
        cin>>v[i];
        w[i] = v[i];
    }
    for(int i = 1;i <= h;i++){
        for(int j = 0;j <= c;j++){
            if(j >= w[i-1]){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[h][c];
    return 0;
}