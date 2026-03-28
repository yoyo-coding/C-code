#include<bits/stdc++.h>
using namespace std;

const int N = 50005;

int n, m;
int a[N];
int st_max[N][17];
int st_min[N][17];
int lg[N];

void build() {
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i >> 1] + 1;
    
    for (int i = 1; i <= n; i++) {
        st_max[i][0] = a[i];
        st_min[i][0] = a[i];
    }
    
    for (int j = 1; j < 17; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
            st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query_max(int l, int r) {
    int k = lg[r - l + 1];
    return max(st_max[l][k], st_max[r - (1 << k) + 1][k]);
}

int query_min(int l, int r) {
    int k = lg[r - l + 1];
    return min(st_min[l][k], st_min[r - (1 << k) + 1][k]);
}

int main() {
    freopen("stock2.in", "r", stdin);
    freopen("stock2.out", "w", stdout);
    if (!(cin>>n>>m)) return 0;
    
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    
    build();
    
    while (m--) {
        int l, r;
        cin>>l>>r;
        cout<<query_max(l, r) - query_min(l, r)<<endl;
    }
    
    return 0;
}
