#include<bits/stdc++.h>
using namespace std;
int main() {
    queue<int> man;
    queue<int> woman;
    int m,w,n;
    cin>>m>>w;
    cin>>n;
    for(int i = 1;i <= m;i++){
        man.push(i);
    }
    for(int i = 1;i <= w;i++){
        woman.push(i);
    }
    for(int i = 0;i < n;i++){
        cout<<man.front()<<" "<<woman.front()<<endl;
        man.push(man.front());
        woman.push(woman.front());
        man.pop();
        woman.pop();
    }
    
    return 0;
}