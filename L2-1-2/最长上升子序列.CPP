#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int nums[N],dp[N];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>nums[i];
    dp[1] = 1;
    int res = 1;
    for(int i = 2;i <= n;i++){
        int max_pre = 0;
        for(int j = 1;j < i;j++){
            if(nums[i] > nums[j]){
                max_pre = max(max_pre,dp[j]);
            }        
        }
        dp[i] = max_pre + 1;
        res = max(res,dp[i]);
    }
    cout<<res;
}