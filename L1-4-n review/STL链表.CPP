#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n,tmp;
    list<int> a;
    cin>>n;
    for(int i = 0;i < n;i++){
        tmp = 0;
        cin>>tmp;
        a.push_back(tmp);
    }
    a.sort();
    auto it = a.begin();
    for(int i = 0;i < n;i++){
        cout<<*it<<" ";
        it++;
    }
    return 0;
}