#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a[10] = {},tmp;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>tmp;
        a[tmp]++;
    }
    for(int i = 0;i <= 9;i++){
        cout<<a[i]<<" ";
    } 
    return 0;
    
}