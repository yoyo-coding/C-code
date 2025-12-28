#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[100005],g[100005],a[100005],h[100005];
int main() {
    int n = 1;
    h[1] = 0x3f3f3f3f;
    while(cin>>a[n]){
        n++;
    }
    n--;
    for(int i = 1;i <= n;i++){
        dp[i] = 1;
        g[i] = 1;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j < i;j++){
            if(a[i] >= a[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j < i;j++){
            if(a[j] < a[i]){
                g[i] = max(g[i],g[j]+1);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        ans = max(ans,dp[i]);
    }
    cout<<ans<<endl;
    ans = 0;
    for(int i = 1;i <= n;i++){
        ans = max(ans,g[i]);
    }
    cout<<ans;
    return 0;
}