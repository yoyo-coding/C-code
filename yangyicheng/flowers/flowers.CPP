#include<bits/stdc++.h>
using namespace std;
int n,x[10005],ans;
int main() {
    freopen("flowers.in","r",stdin);
    freopen("flowers.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>x[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= x[i];i++){
            if((x[i]-j)%2!=0 && (x[i]-j)%3!=2){
                ans+=j;
            }
        }
    }
    cout<<ans;
    return 0;
}