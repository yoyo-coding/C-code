#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> a;
    int n,tmp;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    for(int i = 0;i < n;i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    auto it = a.begin();
    for(it = a.begin(); it != a.end(); it++){
        cout<<*it<<" ";
    }
    
    return 0;
}