#include<bits/stdc++.h>
using namespace std;
struct rain{
    int s,t;
}rainy[1005];
int n;
char c;
bool cmp(rain a,rain b){
    if(a.s-b.s)return a.s < b.s;
    return a.t < b.t;
}
int main() {
    freopen("rain.in","r",stdin);
    freopen("rain.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>rainy[i].s>>c>>rainy[i].t;
    }
    sort(rainy+1,rainy+n+1,cmp);
    for(int i = 1;i <= n;i++){
        if(rainy[i].s % 5 != 0) rainy[i].s = rainy[i].s / 5 * 5;
        if(rainy[i].t % 5 != 0){
            rainy[i].t = rainy[i].t / 5 * 5 + 5;
            if(rainy[i].t % 100 >= 60) rainy[i].t = rainy[i].t / 100 * 100 + 100;
        }
    }
    int ss = rainy[1].s,tt = rainy[1].t;
    for(int i = 2;i <= n;i++){
        if(rainy[i].s <= tt){
            tt = max(tt,rainy[i].t);
        }else{
            printf("%04d-%04d\n",ss,tt);
            ss = rainy[i].s;
            tt = rainy[i].t;
        }
    }
    printf("%04d-%04d\n",ss,tt);
    return 0;
}