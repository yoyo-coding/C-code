#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,tmp;
    cin>>n;
    int a[105],k = 0;
    for(int i = 1;i<= n;i++){
        cin>>tmp;
        if(tmp != 1){
            a[k++] = tmp;
        }
    }
    for(int i = 0;i<k;i++){
        cout<<a[i]<<" ";
    }
    return 0;
    
}