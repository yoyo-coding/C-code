#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
ll a[100005];
ll prefix_sum[100005];
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + a[i];
    }
    ll max_sum = 0;
    int left = 1;
    for(int right = 1; right <= n; right++) {
        while(a[right] - a[left] > k) {
            left++;
        }
        max_sum = max(max_sum, prefix_sum[right] - prefix_sum[left-1]);
    }
    
    cout << max_sum << endl;
    return 0;
}