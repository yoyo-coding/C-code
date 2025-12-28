#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,v = 0;
    cin>>n;
    for(int i = 1;i <= n;i++){
        if(i%3 == 0 || i%5 == 0){
            continue;
        }
        cout<<i<<" ";
        v++;
    }
    cout<<endl;
    cout<<v;    
    return 0;
    
}