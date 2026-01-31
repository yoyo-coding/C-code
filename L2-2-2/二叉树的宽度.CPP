#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int l,r;
}tree[10005];
int n;
queue<node> q;
int tree_w(int root){
    if(root == 0) return 0;
    
    int max_width = 0;
    queue<node> q;
    q.push(tree[root]);
    
    while(!q.empty()){
        int level_size = q.size();
        max_width = max(max_width, level_size);
        
        while(level_size--){
            node tmp = q.front();
            q.pop();
            if(tmp.l != 0) q.push(tree[tmp.l]);
            if(tmp.r != 0) q.push(tree[tmp.r]);
        }
    }
    return max_width;
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>tree[i].l>>tree[i].r;
    }
    cout<<tree_w(1)<<endl;
    return 0;
}