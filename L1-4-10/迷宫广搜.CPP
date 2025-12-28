#include<bits/stdc++.h>
using namespace std;
int n,m;
bool vis[105];
queue <int> q;
int mm[1005][1005];
void bfs(){
    q.push(1);
    vis[1] = 1;
    

}
int main(){
    cin>>n>>m;
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= m;j++){
            cin>>mm[i][j];
        }
    }
    while(!q.empty()){

    }
    return 0;
}