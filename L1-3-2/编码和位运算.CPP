#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int tmp,all = 0;
    cin>>n;
    for(int i = 1 ; i <= n ;i++){
        cin>>tmp;
        all+=tmp;
    }
    if((all&1) == 1){
        cout<<"Alice";
    }
    else{
        cout<<"Bob";
    }
    return 0;
    
}