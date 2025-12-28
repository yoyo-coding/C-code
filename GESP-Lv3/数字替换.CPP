#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int main() {
    int n,k,maxa = -1e5-5,mina = INF;
    int a[100005] = {};
    cin>>n>>k;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    for(int i = 0; i < n;i++){
        if(a[i] > maxa){
            maxa = a[i];
        }
        if(a[i] < mina){
            mina = a[i];
        }
    }
    for(int i = 0; i < n;i++){
        if(a[i] < k){
            a[i] = mina;
        }else if(a[i] > k){
            a[i] = maxa;
        }else if(a[i] == k){
            continue;
        }
    }
    for(int i = 0;i < n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}