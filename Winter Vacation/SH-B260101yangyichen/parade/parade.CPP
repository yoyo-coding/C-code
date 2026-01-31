#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("parade.in", "r", stdin);
    freopen("parade.out", "w", stdout);
    int k;
    cin>>k;
    vector<vector<int>> cls(k);
    
    for (int i = 0; i < k; i++) {
        int c;
        cin>>c;
        cls[i].resize(c);
        for (int j = 0; j < c; j++) {
            cin>>cls[i][j];
        }
        sort(cls[i].begin(), cls[i].end());
    }
    
    vector<pair<int, int>> hts;
    for (int i = 0; i < k; i++) {
        for (int h : cls[i]) {
            hts.push_back({h, i});
        }
    }

    sort(hts.begin(), hts.end());
    
    int mr = 0x3f3f3f3f;
    vector<int> cnt(k, 0);
    int tot = 0;
    
    int l = 0;
    for (int r = 0; r < hts.size(); r++) {
        int h = hts[r].first;
        int c = hts[r].second;
        
        if (cnt[c] == 0) {
            tot++;
        }
        cnt[c]++;
        
        while (tot == k) {
            mr = min(mr, hts[r].first - hts[l].first);
            
            int lc = hts[l].second;
            cnt[lc]--;
            if (cnt[lc] == 0) {
                tot--;
            }
            l++;
        }
    }
    
    cout<<mr<<endl;
    return 0;
}