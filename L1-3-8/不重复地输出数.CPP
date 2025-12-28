#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    for(int i = 1;i < n;i++){
        bool flag = 1;
        for(int j = 1;j <= n-i;j++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
                flag = 0;
            }
        }
        if(flag){
            break;
        }
    }
    int tmp = a[1];
    cout<<a[1];
    for(int i = 2;i <= n;i++){
        if(a[i] != tmp){
            cout<<" "<<a[i];
            tmp = a[i];
        }
        else{
            continue;
        }
    }
    return 0;
}