#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);
    
    int n;
    cin>>n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    
    //只有一个数或两个数
    if (n == 1) {
        cout<<a[1]<<endl;
        return 0;
    }
    if (n == 2) {
        cout<<max(a[1], a[2])<<endl;
        return 0;
    }
    
    //不选第n个数字，在[1, n-1]范围内
    vector<ll> dp1(n + 1, 0);
    dp1[1] = a[1];
    dp1[2] = max(a[1], a[2]);
    for (int i = 3; i <= n - 1; i++) {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + a[i]);
    }
    ll ans1 = dp1[n - 1];
    
    //选第1个数字（则不能选第n个），在[2, n]范围内
    vector<ll> dp2(n + 1, 0);
    dp2[2] = a[2];
    dp2[3] = max(a[2], a[3]);
    for (int i = 4; i <= n; i++) {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + a[i]);
    }
    ll ans2 = dp2[n];
    
    cout<<max(ans1, ans2)<<endl;
    
    return 0;
}
