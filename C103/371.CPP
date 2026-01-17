#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
struct node{
    int st;
    int ed;
}t[100005];
bool cmp(const node& a,const node& b){
    return a.st < b.st || 
}

int main() {
    cin>>n>>m;
    for(int i = 0;i < m;i++){
        cin>>t[i].st>>t[i].ed;
    }
    sort(t,t+m,cmp);
    int s = 1,t = 100,cnt = 0;
    for(int i = 0;i < n && s < t;i++){
        for(int j = i;j < m;j++){
            if()
        }
    }
    return 0;
}