#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[1005];
int c,n,g;
int w[1005],v[1005],p[1005];

int main() {
    cin>>c>>n>>g;
    for(ll i = 0;i < n;i++){
        cin>>w[i]>>v[i]>>p[i];
    }
    memset(dp,0,sizeof(dp));
    for(ll i = 0;i <= g;i++){
        for(ll j = c;j >= 0;j--){
            for(ll k = 0;k <= w[i].size();k++){
                if(j >= w[i][k]){
                    dp[j] = max(dp[j],dp[j - w[i][k]] + v[i][k]);
                }
            }
        }
    }
    cout<<dp[c]<<endl;
    return 0;
}
