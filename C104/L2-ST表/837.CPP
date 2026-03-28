#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m;
int a[N];
int st[N][18];
int lg[N];

void build() {
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i >> 1] + 1;
    
    for (int i = 1; i <= n; i++)
        st[i][0] = a[i];
    
    for (int j = 1; j < 18; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) {
    int k = lg[r - l + 1];
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    freopen("improvement.in", "r", stdin);
    freopen("improvement.out", "w", stdout);
    if (!(cin>>m>>n)) return 0;
    
    for (int i = 1; i <= n; i++) {
        int last_year_rank;
        cin>>last_year_rank;
        a[last_year_rank] = i;
    }
    
    build();
    
    vector<int> out;
    while (m--) {
        int l, r;
        cin>>l>>r;
        out.push_back(query(l, r));
    }
    
    for (size_t i = 0; i < out.size(); ++i) {
        if (i) cout<<' ';
        cout<<out[i];
    }
    
    return 0;
}
