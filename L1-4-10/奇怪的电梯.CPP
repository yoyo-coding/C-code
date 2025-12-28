#include<bits/stdc++.h>
using namespace std;
int step[205],k[205],vis[205];
int d[2] = {1,-1};
queue<int> q;
int main(){
    int a,b,n;
    cin>>n>>a>>b;
    for(int i = 1;i <= n;i++){
		cin>>k[i];
    }
    q.push(a);
    while(!q.empty()){
        int t = q.front();
        if(t == b){
            cout<<step[b];
            return 0;
        }
        q.pop();
        for(int i = 0;i < 2;i++){
            int t1 = t + d[i] * k[t];
            if(t1 >= 0 && t1 <= n && vis[t1] == 0){
                q.push(t1);
                vis[t1] = 1;
                step[t1] = step[t] + 1;
            }
        }
    }
    cout<<-1;
    return 0;
}