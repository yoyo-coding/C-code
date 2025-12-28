#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int a[100005];
int main() {
    cin>>n;
    a[1] = 1;
    for(int i = 2;i <= n;i++){
        bool flag = false;
        for(int j = 1;j < i;j++){
            if(a[j] == a[i-1]-i){
                flag = true;
                break;
            }
        }
        if(a[i-1]-i > 0 && flag == false){
            a[i] = a[i-1]-i;
        }else{
            a[i] = a[i-1]+i;
        }
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}