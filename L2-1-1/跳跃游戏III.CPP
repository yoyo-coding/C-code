#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int n,start,arr[1005],vis[1005];
bool bfs(){
    if(arr[start]==0){
        return true;
    }
    q.push(start);
    vis[start]=1;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(t+arr[t]<n && !vis[t+arr[t]]){
            if(arr[t+arr[t]]==0){
                return true;
            }
            vis[t+arr[t]]=1;
            q.push(t+arr[t]);
        }
        if(t-arr[t]>=0 && !vis[t-arr[t]]){
            if(arr[t-arr[t]]==0){
                return true;
            }
            vis[t-arr[t]]=1;
            q.push(t-arr[t]);
        }

    }
    return false;

}
int main() {
    cin>>n>>start;
    for(int i = 0; i < n; i++){ 
        cin>>arr[i];
    }
    if(bfs()){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}