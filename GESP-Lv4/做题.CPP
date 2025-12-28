#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll q[10000005];
int main() {
    cin>>n;
    for(ll i = 1;i <= n;i++){
        cin>>q[i];
    }
    sort(q+1,q+n+1);
    ll ans = 0,temp = 1;
    for(ll i = 1;i <= n;i++){
        if(q[i] >= temp){
            ans++;
            temp++;
        }else if(q[i]+1 >= temp){
            ans++;
            temp+=2;
        }
    }
    cout<<ans;
    return 0;
}