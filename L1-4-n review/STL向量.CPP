#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n,tmp;
    cin>>n;
    vector<int> a;
    for(int i = 0;i < n;i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    a.resize(20);
    for(int i = 0;i < n;i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    auto it = a.begin();
    for(;it != a.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}