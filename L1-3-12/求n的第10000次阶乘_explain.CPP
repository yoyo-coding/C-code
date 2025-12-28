#include<bits/stdc++.h>
using namespace std;
int a[1000000] = {0,1};
int main() {
    int n,x = 0,len = 1;
    cin>>n;
    for(int i = 1;i <= n;i++){
        x = 0;
        for(int j = 1;j <= len;j++){
            a[j] = a[j] * i + x;
            x = a[j] / 10;
            a[j] %= 10;
            if(j == len && x > 0){
                len++;
            }
        }
    }
    for(int i = len ; i >= 1;i--){
        cout<<a[i];
    }
    return 0;
}