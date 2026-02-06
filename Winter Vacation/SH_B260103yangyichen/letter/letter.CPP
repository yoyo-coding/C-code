#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, f[N], pre[N], cnt[N];
string s;

int calc(int l, int r) {
    int res = 0;
    for (int i = l; i < r; i++)
        res += abs(s[i] - s[i+1]);
    return res;
}

int main() {
    freopen("letter.in", "r", stdin);
    freopen("letter.out", "w", stdout);
    
    cin >> s;
    n = s.length();
    
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    cnt[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int val = calc(j, i-1);
            int tot = f[j] + val + cnt[j];
            
            if (tot < f[i]) {
                f[i] = tot;
                pre[i] = j;
                cnt[i] = cnt[j] + 1;
            } else if (tot == f[i] && j > pre[i]) {
                pre[i] = j;
                cnt[i] = cnt[j] + 1;
            }
        }
    }
    
    vector<int> v;
    int x = n;
    while (x > 0) {
        v.push_back(pre[x]);
        x = pre[x];
    }
    reverse(v.begin(), v.end());
    
    int st = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = st; j < v[i]; j++)
            cout << s[j];
        if (i < v.size() - 1) cout << " ";
        st = v[i];
    }
    for (int j = st; j < n; j++)
        cout << s[j];
    cout<<endl;
    
    return 0;
}