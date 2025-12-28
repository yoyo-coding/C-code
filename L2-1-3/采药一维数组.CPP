#include<bits/stdc++.h>
using namespace std;
int dp[10005];
int v[10005],w[10005];
int c,h;

int main() {
    cin>>c>>h;
    for(int i = 0;i < h;i++){
        cin>>w[i]>>v[i];
    }
    for(int i = 0;i < h;i++){
        for(int j = c;j >= w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[c];
    return 0;
}