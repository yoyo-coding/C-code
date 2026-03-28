#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 200005;
const int MAXV = 10005;

int n;
int x[MAXN], d[MAXN];
int bit[MAXV * 2];

void update(int idx, int val) {
    for (; idx < MAXV * 2; idx += idx & -idx)
        bit[idx] += val;
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}

int main() {
    freopen("score.in", "r", stdin);
    freopen("score.out", "w", stdout);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    
    memset(bit, 0, sizeof(bit));
    
    for (int i = 1; i <= n; i++) {
        int score = x[i];
        int diff = d[i];
        
        int l = max(0, score - diff);
        int r = min(10000, score + diff);
        
        int ans = query(r + 1) - query(l);
        
        cout << ans << (i == n ? "" : " ");
        
        update(score + 1, 1);
    }
    
    cout << endl;
    
    return 0;
}