#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1000005;
int n;
ll a[MAXN];
ll pre[MAXN];

int main(){
    freopen("invest.in", "r", stdin);
    freopen("invest.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    ll max_sum = LLONG_MIN;
    ll min_pre = 0;

    for(int i = 1; i <= n; i++) {
        ll c = pre[i] - min_pre;
        if(c > max_sum) {
            max_sum = c;
        }
        if(pre[i] < min_pre) {
            min_pre = pre[i];
        }
    }

    ll cnt = 0;
    map<ll, int> freq;
    freq[0] = 1;

    for(int i = 1; i <= n; i++) {
        if(freq.find(pre[i] - max_sum) != freq.end()) {
            cnt += freq[pre[i] - max_sum];
        }
        freq[pre[i]]++;
    }

    cout<<max_sum<<" "<<cnt<<endl;
    return 0;
}