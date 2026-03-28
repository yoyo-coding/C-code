#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 200005;
const int MAXV = 10005;
int n;
int x[MAXN];
int bit[MAXV];

int lowbit(int i) {
    return i & (-i);
}

void update(int pos, int val) {
    for (int i = pos; i < MAXV; i += lowbit(i)) {
        bit[i] += val;
    }
}
int query(int pos) {
    int res = 0;
    for (int i = pos; i > 0; i -= lowbit(i)) {
        res += bit[i];
    }
    return res;
}

int main() {
    freopen("rank.in", "r", stdin);
    freopen("rank.out", "w", stdout);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    
    for (int i = 1; i <= n; i++) {
        int score = x[i];
        int greater = (i - 1) - query(score + 1);
        int rank = greater + 1;
        
        cout << rank << (i == n ? "" : " ");
        
        update(score + 1, 1);
    }
    cout << endl;
    
    return 0;
}