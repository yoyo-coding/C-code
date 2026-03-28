#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m;
int a[N];
int st[N][20];
int lg[N];

void build() {
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i >> 1] + 1;
    
    for (int i = 1; i <= n; i++)
        st[i][0] = a[i];
    
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) {
    int k = lg[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    if (!(cin>>n>>m)) return 0;
    
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    
    build();
    
    while (m--) {
        int l, r;
        cin>>l>>r;
        cout<<query(l, r)<<endl;
    }
    
    return 0;
}