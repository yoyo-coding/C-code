#include<bits/stdc++.h>
using namespace std;
int m,n;
int dp[20010];
int w[40];
int main(){
    int i,j;
    cin>>m>>n;
    for(i=1;i<=n;i++){
        cin>>w[i];
    }
    for(i=1;i<=n;i++){
        for(j=m;j>=w[i];j--){                           
            if(dp[j]<dp[j-w[i]]+w[i]){
                dp[j]=dp[j-w[i]]+w[i];
            }
        }
    }
    cout<<m-dp[m];
    return 0;
}
