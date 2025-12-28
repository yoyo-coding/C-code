#include<bits/stdc++.h>
using namespace std;
int a[50];
int main(){
    int n,r;
    cin>>n>>r;
    for(int s = (1<<n)-1 ; s>=0 ; s--){
        int cnt = 0;
        for(int i = 0 ; i<n ; i++){
            if(s&(1<<i)){
                a[cnt++] = i;
            }
        }
        if(cnt==r){
            for(int i = r - 1 ; i>= 0 ; i-- ){
                printf("  %d",n-a[i]);
            }
            puts("");
        }
    }
    return 0;
    
}