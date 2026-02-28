#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int n, q, s, t;
    cin>>n>>q>>s>>t;
    
    vector<ll> a(n+1);
    for (int i = 0; i <= n; i++){
        cin>>a[i];
    }
    
    ll e = 0;
    for (int i = 0; i < n; i++){
        if (a[i] < a[i+1]){
            e -= 1LL * (a[i+1] - a[i]) * s;
        } else if (a[i] > a[i+1]){
            e += 1LL * (a[i] - a[i+1]) * t;
        }
    }
    
    for (int j = 0; j < q; j++){
        int l, r, x;
        cin>>l>>r>>x;
        ll oc = 0;
        ll nc = 0;
        if (l > 0){
            if (a[l-1] < a[l]){
                oc += 1LL * (a[l] - a[l-1]) * s;
            } else if (a[l-1] > a[l]){
                oc -= 1LL * (a[l-1] - a[l]) * t;
            }
        }
        if (r < n){
            if (a[r] < a[r+1]){
                oc += 1LL * (a[r+1] - a[r]) * s;
            } else if (a[r] > a[r+1]){
                oc -= 1LL * (a[r] - a[r+1]) * t;
            }
        }
        for (int i = l; i <= r; i++){
            a[i] += x;
        }
        if (l > 0){
            if (a[l-1] < a[l]){
                nc += 1LL * (a[l] - a[l-1]) * s;
            } else if (a[l-1] > a[l]){
                nc -= 1LL * (a[l-1] - a[l]) * t;
            }
        }
        
        if (r < n){
            if (a[r] < a[r+1]){
                nc += 1LL * (a[r+1] - a[r]) * s;
            } else if (a[r] > a[r+1]){
                nc -= 1LL * (a[r] - a[r+1]) * t;
            }
        }
        e = e - oc + nc;
        
        cout<<e<<endl;
    }
    
    return 0;
}