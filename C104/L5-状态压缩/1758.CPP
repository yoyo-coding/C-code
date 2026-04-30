#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=100000000;
int n,m;
int mp[15];
int state[5000],cnt;
int dp[15][5000];

bool check(int s){
    return (s&(s<<1))==0;
}

bool fit(int s,int row){
    return (s&mp[row])==s;
}

int main(){
    freopen("plan3.in","r",stdin);
    freopen("plan3.out","w",stdout);
    
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            mp[i]=(mp[i]<<1)|x;
        }
    }
    
    int max_state=(1<<m);
    for(int i=0;i<max_state;i++){
        if(check(i)){
            state[++cnt]=i;
        }
    }
    
    dp[0][1]=1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cnt;j++){
            if(!fit(state[j],i)) continue;
            
            for(int k=1;k<=cnt;k++){
                if(!fit(state[k],i-1)) continue;
                
                if(state[j]&state[k]) continue;
                
                dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
            }
        }
    }
    
    int ans=0;
    for(int i=1;i<=cnt;i++){
        ans=(ans+dp[n][i])%MOD;
    }
    
    cout<<ans<<endl;
    
    return 0;
}