#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N=500005;
ll h[N],e[N],ne[N],idx;
ll a[N],cnt;

void add(ll u,ll v) {
    e[idx]=v,ne[idx]=h[u],h[u]=idx++;
}

int main() {
    ll t;
    cin>>t;
    
    while(t--) {
        ll n,m;
        cin>>n>>m;
        
        for(ll i=1;i<=n;i++) h[i]=-1;
        idx=0;
        
        for(ll i=0;i<m;i++) {
            ll u,v;
            cin>>u>>v;
            add(u,v);
        }
        
        for(ll i=1;i<=n;i++) {
            cnt=0;
            for(ll j=h[i];j!=-1;j=ne[j]) {
                a[cnt++]=e[j];
            }
            sort(a,a+cnt);
            for(ll j=0;j<cnt;j++) {
                cout<<a[j];
                if(j!=cnt-1) cout<<" ";
            }
            cout<<endl;
        }
    }
    
    return 0;
}