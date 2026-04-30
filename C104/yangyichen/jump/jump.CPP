#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[10005];
int main() {
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int q=1;q<=m;q++){
        int i,d,k;
        cin>>i>>d>>k;
        int sum=0;
        for(int j=0;j<=k;j++){
            int pos=i+j*d;
            if(pos<=n){
                sum+=a[pos];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}