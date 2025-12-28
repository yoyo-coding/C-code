#include<bits/stdc++.h>
using namespace std;
int f(int x){
    int sum = 0;
    for(int i = 1;i <= x;i++){
        sum+=i;
    }
    return sum;
}

int main(){
    int x,y,z;
    cin>>x>>y>>z;
    cout<<f(x)<<endl;
    cout<<f(y)<<endl;
    cout<<f(z)<<endl;
    return 0;
    
}