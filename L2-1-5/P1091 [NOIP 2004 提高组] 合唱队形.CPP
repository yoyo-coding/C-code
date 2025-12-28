#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[1005],front[1005],back[1005];
int n;
int maxn = 0;
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>front[i];
        dp[i] = 1;
        back[i] = 1;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1; j < i;j++){
            if(front[i] > front[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    for(int i = n;i >= 1;i--){
        for(int j = n;j > i;j--){
            if(front[i] > front[j]){
                back[i] = max(back[i],back[j]+1);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        maxn = max(maxn,dp[i]+back[i]-1);
    }
    cout<<n-maxn;
    return 0;
}