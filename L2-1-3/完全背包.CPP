#include<bits/stdc++.h>
using namespace std;
int a,m,c;
int v[10005],w[10005],f[10005][10005];
int main() {
    cin>>a>>m;
    for(int i = 1;i <= m;i++){
        cin>>v[i]>>w[i];
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= a;j++){
            f[i][j] = f[i-1][j];
            if(j >= v[i]){
                f[i][j] = max(f[i][j],f[i][j-v[i]]+w[i]);
            }
        }
    }
    cout<<f[m][a];
    return 0;
}