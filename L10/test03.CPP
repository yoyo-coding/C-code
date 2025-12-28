#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i = 1;i <= 9;i++){
        if((i*10 + 3)*6528 == (30+i)*8256){
            cout<<i;
            break;
        }
    }
    return 0;
    
}