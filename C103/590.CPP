#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,p,m;
struct edge{
    int s,e,t;
}edges[1005];
int bellman_ford(){
    ll d[1005];
    for(int i = 1;i <= n;i++)d[i] = 1e8;
    d[1] = 0;
    for(ll k = 1;k < n-1;k++){
        for(ll u = 1;u <= n;u++){
            for(int i = 0;i < p;i++){
                d[edges[i].e] = min(d[edges[i].e],d[edges[i].s] + edges[i].t);
            }
        }
    }
    for(ll u = 1;u <= n;u++){
        for(ll i = 0;i < p;i++){
            if(d[edges[i].e] > d[edges[i].s] + edges[i].t){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    // freopen("timemachine.in", "r", stdin);
    // freopen("timemachine.out", "w", stdout);
    cin>>n>>p>>m;
    for(int i = 0;i < p;i++){
        cin>>edges[i].s>>edges[i].e>>edges[i].t;
    }
    if(bellman_ford()){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}