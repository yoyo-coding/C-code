#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5][6];
    int k,tmp = 0;
    cin>>k;
    for(int i  = 1;i <= 4;i++){
        for(int j = 1;j <= 5;j++){
            cin>>a[i][j];
            if(i+j == k){
                cout<<a[i][j]<<" ";
                tmp = 1;
            }
        }
    }
    if(tmp == 0){
        cout<<"none";
    }
    return 0;
    
}