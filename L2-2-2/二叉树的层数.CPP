#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int l,r;
}tree[100005];
int n;
queue<node> q;
int tree_h(int root){
    int h = 0;
    q.push(tree[root]);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            node tmp = q.front();
            q.pop();
            if(tmp.l ) q.push(tree[tmp.l]);
            if(tmp.r ) q.push(tree[tmp.r]);
        }
        h++;
    }
    return h;
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>tree[i].l>>tree[i].r;
    }
    cout<<tree_h(1);
    return 0;
}