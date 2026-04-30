#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int a, n;
    freopen("blah.in", "r", stdin);
    freopen("blah.out", "w", stdout);
    
    cin>>a>>n;
    
    vector<ll> blah;
    set<ll> visited;
    
    blah.push_back(a);
    visited.insert(a);
    
    ll result = a;
    
    for (int i = 1; i <= n; i++) {
        sort(blah.begin(), blah.end());
        
        result = blah[0];
        blah.erase(blah.begin());
        
        ll x1 = 2 * result + 1;
        ll x2 = 3 * result + 1;
        
        if (visited.find(x1) == visited.end()) {
            blah.push_back(x1);
            visited.insert(x1);
        }
        
        if (visited.find(x2) == visited.end()) {
            blah.push_back(x2);
            visited.insert(x2);
        }
    }
    
    cout<<result<<endl;
    
    return 0;
}