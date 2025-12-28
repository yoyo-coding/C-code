#include<bits/stdc++.h>
using namespace std;
int dp[505][505];
int a[500005],b[500005];
int main() {
    int na,nb;
    cin>>na>>nb;
    for(int i = 1;i <= na;i++){
        cin>>a[i];
    }
    for(int i = 1;i <= nb;i++){
        cin>>b[i];
    }
    for(int i = 1;i <= na;i++){
        for(int j = 1;j <= nb;j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(a[i] == b[j]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
            }
        }
    }
    cout<<dp[na][nb];
    return 0;
}