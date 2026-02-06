#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("shuttle.in", "r", stdin);
    freopen("shuttle.out", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    vector<pair<int,int>> s(n);
    for(int i=0; i<n; i++) {
        cin >> s[i].first >> s[i].second;
    }
    
    sort(s.begin(), s.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
    });
    
    int ans = 0, i = 0;
    while(i < n) {
        ans++;
        int t = s[i].second;
        int cnt = 0;
        while(i < n && cnt < k && s[i].first <= t) {
            cnt++;
            i++;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}
