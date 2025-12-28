#include<bits/stdc++.h>
using namespace std;
int dp[100005];
int v[100005],w[100005];
long long a,b;
int main() {
    cin>>a>>b;
    for(int i = 0;i < a;i++){
        cin>>w[i]>>v[i];
    }
    for(int i = 0;i < b;i++){
        for(int j = a;j >= w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[a];
    return 0;
}