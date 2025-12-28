#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 200005;
const int MAX_ITEMS = 300;
ll dp[MAXN];
int b[MAX_ITEMS];
int v[MAX_ITEMS];
int a[100];
int main() {
    int n,m,k,V;
    cin>>n>>m>>k>>V;
    for(int i = 0; i < n + m + k; i++) {
        cin>>b[i];
    }
    for(int i = 0; i < n + m + k; i++) {
        cin>>v[i];
    }
    for(int i = 0; i < k; i++) {
        cin>>a[i];
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) {
        for(int j = b[i]; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - b[i]] + v[i]);
        }
    }
    for(int i = n; i < n + m; i++) {
        for(int j = V; j >= b[i]; j--) {
            dp[j] = max(dp[j], dp[j - b[i]] + v[i]);
        }
    }
    for(int i = 0; i < k; i++) {
        int item_idx = n + m + i;
        int num = a[i];
        
        for(int j = 1; j <= num; j <<= 1) {
            int weight = j * b[item_idx];
            int value = j * v[item_idx];
            for(int l = V; l >= weight; l--) {
                dp[l] = max(dp[l], dp[l - weight] + value);
            }
            num -= j;
        }
        if(num > 0) {
            int weight = num * b[item_idx];
            int value = num * v[item_idx];
            for(int l = V; l >= weight; l--) {
                dp[l] = max(dp[l], dp[l - weight] + value);
            }
        }
    }

    cout<<dp[V]<<endl;
    
    return 0;
}