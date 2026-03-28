    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long

    const int MAXN = 100005;
    const int MAXV = 100005;

    int n;
    int a[MAXN];
    ll bit[MAXV];

    void update(int idx, int val) {
        for (; idx < MAXV; idx += idx & -idx)
            bit[idx] += val;
    }

    ll query(int idx) {
        ll sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

    int main() {
        freopen("reverse.in", "r", stdin);
        freopen("reverse.out", "w", stdout);
        
        cin >> n;
        
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        
        memset(bit, 0, sizeof(bit));
        
        ll ans = 0;
        
        for (int i = n; i >= 1; i--) {
            ans += query(a[i]);
            update(a[i] + 1, 1);
        }
        
        cout << ans << endl;
        
        return 0;
    }