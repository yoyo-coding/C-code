#include<bits/stdc++.h>
using namespace std;

struct Node{
    char s;
    int y;
    int m;
    int d;
    int num;
};
Node node[1005];

bool cmp(Node a,Node b){
    if(a.y == b.y){
        if(a.m == b.m){
            if(a.d == b.d){
                return a.num>b.num;
            }
            else{
                return a.d < b.d;
            }
        }
        else{
            return a.m < b.m;
        }
    }
    else{
        return a.y < b.y;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>node[i].s>>node[i].y>>node[i].m>>node[i].d;
        node[i].num = i;
    }
    sort(node+1,node+1+n,cmp);
    for(int i = 1;i <= n;i++){
        cout<<node[i].s<<endl;
    }
    return 0;
    
}