#include<bits/stdc++.h>
using namespace std;
int msgcost(int z) {
    if (z <= 70) {
        return 1;
    } 
    else {
        if(z % 70 == 0){
            return z / 70;
        }
        else {
            return z / 70 + 1; 
        }
        
    }
}
int main(){
    int c,z,cnt = 0;
    double res;
    cin>>c;
    for(int i = 1;i <= c;i++){
        cin>>z;
        cnt += msgcost(z);
    }
    res = cnt*0.1;
    cout<<fixed<<setprecision(1)<<res;
    return 0;
    
}