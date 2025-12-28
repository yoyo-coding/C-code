#include<bits/stdc++.h>
using namespace std;
#define ll long long
int w[105][105];
int n,m;
bool check(int xa,int xb,int ya,int yb){
    int a[2] = {0,0};
    for(int i=xa;i<=xb;i++){
        for(int j=ya;j<=yb;j++){
            a[w[i][j]]++;
        }
    }
    return a[0] == a[1];
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin>>w[i][j];
        }
    }
    int ans = 0;
    for(int ai = 1;ai <= n;ai++){
        for(int aj = 1;aj <= m;aj++){
            for(int bi = ai;bi <= n;bi++){
                for(int bj = aj;bj <= m;bj++){
                    if(check(ai,bi,aj,bj)){
                        ans = max(ans,(bi-ai+1)*(bj-aj+1));
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}