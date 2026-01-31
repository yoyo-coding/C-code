#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int l,r;
}tree[100005];
int n;
int tree_h(int x){
    if(!x) return 0;
    return max(tree_h(tree[x].l),tree_h(tree[x].r))+1;
}
int isBalanced(int root){
    if(!root) return 1;
    int lh = tree_h(tree[root].l);
    int rh = tree_h(tree[root].r);
    if(abs(lh-rh)>1) return 0;
    return isBalanced(tree[root].l)&&isBalanced(tree[root].r);
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>tree[i].l>>tree[i].r;
    }
    if(isBalanced(1)) cout<<"Yes";
    else cout<<"No";
    return 0;
}