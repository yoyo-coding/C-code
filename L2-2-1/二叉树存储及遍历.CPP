#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    char l;
    char r;
}tree[100005];
void pre_order(int x);
void in_order(int x);
void post_order(int x);
int main() {
    int n;
    cin>>n;
    char root;
    for(int i = 1;i <= n;i++){
        char a,b,c;
        cin>>a>>b>>c;
        tree[int(a)].l=b;
        tree[int(a)].r=c;
        if(i == 1) root = a;
    }
    pre_order(root);
    cout<<endl;
    return 0;
}
void pre_order(int x){
    if(x == '*') return;
    cout<<x;
    pre_order(tree[x].l);
    pre_order(tree[x].r);
}
void in_order(int x){
    if(x == '*') return;
    in_order(tree[x].l);
    cout<<x;
    in_order(tree[x].r);
}
void post_order(int x){
    if(x == '*') return;
    post_order(tree[x].l);
    post_order(tree[x].r);
    cout<<x;
}