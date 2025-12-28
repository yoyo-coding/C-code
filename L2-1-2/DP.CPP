#include<bits/stdc++.h>
using namespace std;
int fd_recursive(int n){
    if(n == 1)return 1;
    if(n == 0)return 0;

    return fd_recursive(n-1) + fd_recursive(n-2);
}
int fb_dp(int n){
    int dp[45];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2;i <= n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main() {
    cout<<fd_recursive(45)<<endl;
    cout<<fb_dp(45)<<endl;
    return 0;
}