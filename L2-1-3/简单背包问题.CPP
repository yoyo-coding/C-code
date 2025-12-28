#include<bits/stdc++.h>
using namespace std;
int v[10005],w[10005];
int dp[10005][10005];
int a,b;
int main() {
    cin>>a>>b;
    for(int i = 1;i < a;i++){
        cin>>w[i]>>v[i];
    }
    for(int i = 1;i <= a;i++){
        for(int j = 0;j <= b;j++){
            if(j>=w[i]){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if(dp[a][b] == a){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}