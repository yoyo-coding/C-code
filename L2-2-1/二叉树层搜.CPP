#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    char ch;
    int l,r;
}tree[1000];
int cnt = 0;
queue<node> q;
int build(int t){
    char ch;
    cin>>ch;
    if(ch == '.'){
        return 0;
    }
    t = ++cnt;
    tree[t].ch = ch;
    tree[t].l = build(tree[t].l);
    tree[t].r = build(tree[t].r);
    return t;
}
void l_search(int t){
    q.push(tree[t]);
    while(!q.empty()){
        node t = q.front();
        q.pop();
        cout<<t.ch<<" ";
        if(t.l){
            q.push(tree[t.l]);
        }
        if(t.r){
            q.push(tree[t.r]);
        }
    }
    return;
}
int main() {
    int root = build(0);
    l_search(root);
    return 0;
}