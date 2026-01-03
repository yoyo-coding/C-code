#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 20;
int n,m;
int w[N],car[N],ans = N;
void dfs(int u,int k){
    if(k >= ans){
        return;
    }
    if(u == n){
        ans = k;
        return;
    }
    for(int i = 0;i < k;i++){
        if(car[i] + w[u] <= m){
            car[i] += w[u];
            dfs(u+1,k);
            car[i] -= w[u];
        }
    }
    car[k] = w[u];
    dfs(u+1,k+1);
    car[k] = 0;
}
int main() {
    cin>>n>>m;
    for(int i = 0;i < n;i++){
        cin>>w[i];
    }
    sort(w,w+n,greater<int>());
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}