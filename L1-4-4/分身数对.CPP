#include<bits/stdc++.h>
using namespace std;
int main() {
    set<int> s;
    int n,tmp,p,cnt = 0;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>tmp;
        s.insert(tmp);
    }
    auto it = s.begin();
    cin>>p;
    for(it = s.begin();it != s.end();it++){
        if(s.find((p-*it)) != s.end()){
            cnt++;
        }
    }
    cout<<cnt/2;
    return 0;
}