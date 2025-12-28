#include<bits/stdc++.h>
using namespace std;
int main() {
    priority_queue<int, vector<int>, greater<int>> q;
    int n,wri,res = 0,tmp = 0;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>wri;
        q.push(wri); 
    }
    while(!q.empty()) {
        tmp = 0;
        for(int i = 0;i < 2;i++){
            tmp += q.top();
            q.pop();
        }
        res += tmp;
        if(q.empty()) break;
        q.push(tmp);
    }
    cout<<res<<endl;
    return 0;
}