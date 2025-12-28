#include<bits/stdc++.h>
using namespace std;
struct node{
    int l;
    int w;
}stu[10005];
int n,cnt = 0;
int main() {
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>stu[i].l>>stu[i].w;
    }
    for(int i = 0;i < n-1;i++){
        for(int j = 0;j < n-1-i;j++){
            if(stu[j].l < stu[j+1].l || (stu[j].l == stu[j+1].l && stu[j].w < stu[j+1].w)){
                swap(stu[j],stu[j+1]);
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}