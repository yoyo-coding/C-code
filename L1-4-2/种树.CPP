#include<bits/stdc++.h>
using namespace std;
int n,m,f[30005],sum;
struct node{
    int l,r,t;
}a[30005];
bool cmp(node a,node b){
    return a.r < b.r;
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= m;i++){
        cin>>a[i].l>>a[i].r>>a[i].t;
    }
    sort(a+1,a+m+1,cmp);
    for(int i = 1;i <= m;i++){
        int cnt = 0;
        for(int j = a[i].l;j <= a[i].r;j++){
            if(f[j] == 1){
                cnt++;
            }
        }
        if(cnt >= a[i].t){
            continue;
        }
        for(int j = a[i].r;j >= a[i].l;j--){
            if(f[j] == 0){
                f[j] = 1;
                cnt++;
                sum++;
                if(cnt == a[i].t){
                    break;
                }
            }
        }
    }    
    cout<<sum;
    return 0;
}