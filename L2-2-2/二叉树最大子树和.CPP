#include<bits/stdc++.h>
using namespace std;

struct nd{
    int v, l, r;
} t[10005];

int n;
int mx = INT_MIN;

int dfs(int rt){
    if(rt == 0) return 0;
    
    int s = t[rt].v;
    if(t[rt].l != 0) s += dfs(t[rt].l);
    if(t[rt].r != 0) s += dfs(t[rt].r);
    
    mx = max(mx, s);
    return s;
}

int main(){
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> t[i].v;
    for(int i = 1; i <= n; i++){
        cin >> t[i].l >> t[i].r;
    }
    
    dfs(1);
    
    cout << mx << endl;
    
    return 0;
}