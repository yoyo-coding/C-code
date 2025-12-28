#include<bits/stdc++.h>
using namespace std;
int main() {
    list <int> l;
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        l.push_back(i);
    }
    auto it = l.begin();
    while(n--){
        for(int i = 1;i < m;i++){
            it++;
            if(it == l.end()){
                it = l.begin();
            }
            cout<<*it<<" ";
            if(it == l.end()){
                it = l.erase(it);
            }
        }
    }

    
    return 0;
}