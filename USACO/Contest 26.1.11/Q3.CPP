#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll g[505][505];
ll sum[505][505];
ll p[505][505];
ll res = 0;
int main(){
    int n,k;
    cin>>n>>k;
    int q;
    cin>>q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            p[i][j] = g[i][j]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
        }
    }
    for(int i = 1; i <= n-k+1; i++){
        for(int j = 1; j <= n-k+1; j++){
            sum[i][j] = p[i+k-1][j+k-1]-p[i-1][j+k-1]-p[i+k-1][j-1]+p[i-1][j-1];
        }
    }
    for(int i = 0; i < q; i++){
        int r,c;
        ll v;
        cin>>r>>c>>v;
        ll d = v-g[r][c];
        g[r][c] = v;

        for(int i = max(1,r-k+1); i <= min(n-k+1,r); i++){
            for(int j = max(1,c-k+1); j <= min(n-k+1,c); j++){
                sum[i][j] += d;
            }
        }

        for(int i = 1; i <= n-k+1; i++){
            for(int j = 1; j <= n-k+1; j++){
                if(sum[i][j] > res){
                    res = sum[i][j];
                }
            }
        }
        cout<<res<<endl;
    }

    return 0;
}