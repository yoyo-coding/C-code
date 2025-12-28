#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,cnt = 0;
    int a[6] = {1,5,10,20,100,200};
    cin>>n;
    while(n){
        if(n>=a[5]){
            n -= a[5];
        }
        else if(n>=a[4]){
            n -= a[4];
        }
        else if(n>=a[3]){
            n -= a[3];
        }
        else if(n>=a[2]){
            n -= a[2];
        }
        else if(n>=a[1]){
            n -= a[1];
        }
        else if(n>=a[0]){
            n -= a[0];
        }
        cnt++;
    }
    cout<<cnt;

    return 0;
}