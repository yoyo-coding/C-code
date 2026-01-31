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
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>tree[i].l>>tree[i].r;
    }
    cout<<tree_h(1);
    return 0;
}