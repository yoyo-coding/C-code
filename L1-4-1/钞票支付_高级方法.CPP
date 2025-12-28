#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,cnt = 0,tmp = 0;
    int a[6] = {1,5,10,20,100,200};
    cin>>n;
    int i = 5;
    while(n>0){
        tmp = n/a[i];
        if(tmp){
            cnt += tmp;
            n -= tmp*a[i];
        }
        i--;
    }
    cout<<cnt;
    return 0;
}