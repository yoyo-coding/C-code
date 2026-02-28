#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    int N;
    ll K;
    if (!(cin>>N>>K)) return;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin>>A[i];
    }

    if (K < 0) {
        K = -K;
        for (int i = 0; i < N; ++i) {
            A[i] = -A[i];
        }
    }
    ll ElsieNumber = 0;

    vector<vector<ll>> buckets((size_t)K);
    for (int i = 0; i < N; ++i) {
        ll rem = (A[i] % K + K) % K;
        buckets[rem].push_back(A[i]);
    }

    ll total_ops = 0;

    for (int r = 0; r < K; ++r) {
        if (buckets[r].empty()) continue;
        sort(buckets[r].begin(), buckets[r].end());

        ll current_val = buckets[r][0];
        ElsieNumber = current_val;

        for (size_t i = 1; i < buckets[r].size(); ++i) {
            ll target = max(buckets[r][i], current_val + K);
            total_ops += (target - buckets[r][i]) / K;
            current_val = target;
        }
    }

    cout<<total_ops<<endl;
}

int main() {
    int T;
    if (cin>>T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}