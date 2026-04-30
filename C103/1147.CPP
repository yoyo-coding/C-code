#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("xjj.in","r",stdin);
    // freopen("xjj.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    
    deque<int> q;
    vector<int> result;
    
    for(int i = 0; i < n; i++) {
        while(!q.empty() && q.front() <= i-k) {
            q.pop_front();
        }
        
        while(!q.empty() && a[q.back()] >= a[i]) {
            q.pop_back();
        }
        
        q.push_back(i);
        if(i >= k-1) {
            result.push_back(a[q.front()]);
        }
    }
    
    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i != result.size()-1) cout << " ";
    }
    cout << endl;
    
    return 0;
}