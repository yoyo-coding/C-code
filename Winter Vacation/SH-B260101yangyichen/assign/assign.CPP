#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
struct node{
    int b,f;
    int d;
}p[2005];

bool cmp(node a,node b) {
    return a.d > b.d;
}

int main() {
    freopen("assign.in","r",stdin);
    freopen("assign.out","w",stdout);
    cin>>n;
    int all = n*2;
    
    for(int i = 0; i < all; i++) {
        cin>>p[i].b>>p[i].f;
        p[i].d = p[i].b - p[i].f;
    }
    
    sort(p,p+all,cmp);
    
    ll res = 0;
    for(int i = 0; i < n; i++) {
        res += p[i].b;
    }
    for(int i = n; i < all; i++) {
        res += p[i].f;
    }
    cout<<res;
    return 0;
}