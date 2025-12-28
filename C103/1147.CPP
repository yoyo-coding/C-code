#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> q;
vector<int> a;
int main() {
    freopen("xjj.in","r",stdin);
    freopen("xjj.out","w",stdout);
    int n,k,tmp;
    cin>>n>>k;
    for(int i = 0;i < n;i++){
        cin>>a.push_back;
    }
    int l = 0,r = 0;
    for(int i = 0;i < n;i++){
        while(l < r && i - q[l]>=l){
            l++;
        }
        while(l < n&&a[i] - a[q[r]] > k){
            r++;
        }
        q.push_back(i);
    }
    for(int i = l;i < r;i++){
        cout<<a[q[i]]<<" ";
    }
    return 0;
}