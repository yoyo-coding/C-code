#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> cnt(1001, 0);
    
    for (int i = 0; i < n; i++) {
        int s, t;
        cin>>s>>t;
        for (int j = s; j <= t; j++) {
            cnt[j]++;
        }
    }
    
    int max_l = 0;
    for (int i = 1; i <= 1000; i++) {
        max_l = max(max_l, cnt[i]);
    }
    
    cout<<max_l<<endl;
    
    return 0;
}