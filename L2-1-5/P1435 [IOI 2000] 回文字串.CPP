#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,t;
int dp[1005][1005];
int main() {
    cin>>s;
    int len = s.size();
    t = s;
    reverse(t.begin(),t.end());
    for(int i = 1;i <= len;i++){
        for(int j = 1;j <= len;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<len-dp[len][len]<<endl;
    return 0;
}