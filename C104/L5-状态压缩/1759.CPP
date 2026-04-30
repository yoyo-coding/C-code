#include <bits/stdc++.h>
using namespace std;

const int MAXN=17;
const int MAXS=(1<<16)+5;

int n;
int a[MAXN][MAXN];
int dp[MAXN][MAXS];
int valid[MAXS];
int cnt;

bool check(int s){
    return !(s&(s<<1));
}

int calc(int row,int s){
    int sum=0;
    for(int j=0;j<n;j++){
        if(s&(1<<j)){
            sum+=a[row][j];
        }
    }
    return sum;
}

int main(){
    freopen("plan2.in","r",stdin);
    freopen("plan2.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    
    int maxs=1<<n;
    cnt=0;
    for(int s=0;s<maxs;s++){
        if(check(s)){
            valid[cnt++]=s;
        }
    }
    
    for(int i=0;i<cnt;i++){
        dp[0][valid[i]]=calc(0,valid[i]);
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<cnt;j++){
            int cur=valid[j];
            int val=calc(i,cur);
            for(int k=0;k<cnt;k++){
                int pre=valid[k];
                if(!(cur&pre)){
                    dp[i][cur]=max(dp[i][cur],dp[i-1][pre]+val);
                }
            }
        }
    }
    
    int ans=0;
    for(int i=0;i<cnt;i++){
        ans=max(ans,dp[n-1][valid[i]]);
    }
    
    cout<<ans<<endl;
    
    return 0;
}
