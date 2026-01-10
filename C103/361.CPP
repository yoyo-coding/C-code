#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
struct node{
    int si;
    int ti; 
}Time[10005];
bool cmp(const node& a,const node& b){
    return a.ti < b.ti;
}
int main() {
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>Time[i].si>>Time[i].ti;
    }
    sort(Time,Time+n,cmp);
    int cnt = 0; 
    int let = -1;
    
    for(int i = 0; i < n; i++){
        if(Time[i].si >= let){
            cnt++;
            let = Time[i].ti;
        }
    }
    cout<<n - cnt<<endl;
    return 0;
}