#include<bits/stdc++.h>
using namespace std;
int main() {
    set<int> s;
    int n,tmp;
    string cmd;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>cmd;
        if(cmd == "I"){
            cin>>tmp;
            s.insert(tmp);
        }else if(cmd == "Q"){
            cin>>tmp;
            (s.find(tmp) != s.end()) ? cout<<"Yes" : cout<<"No";
        }
    }    
    return 0;
}