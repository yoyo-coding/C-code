#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    int len = 0;
    int n,x;
    cin>>n;
    for(int i = 1; i <= n;i++){
        cin>>x;
        if(binary_search(a+1,a+1+len,x) == false){
            a[++len] = x;
            for(int j = len;j > 1;j--){
                if(a[j] < a[j-1]){
                    swap(a[j],a[j-1]);
                }else{
                    break;
                }
            }
        }
    }
    for(int i = 1;i <= len;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}