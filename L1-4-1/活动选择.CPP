#include<bits/stdc++.h>
using namespace std;
struct se{
    int s;
    int e;
};
se party[1000];
bool cmp(se a,se b){
    return a.e<b.e;
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>party[i].s>>party[i].e;
    }
    sort(party,party+n,cmp);
    int end = party[0].e;
    int cnt = 1;
    for(int i = 1;i <= n;i++){
        if(party[i].s >= end){
            end = party[i].e;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}