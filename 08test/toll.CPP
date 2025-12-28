#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    
    switch(a/1000){
        case 0:
        cout<<"0";
        break;
        case 1:
        case 2:
        case 3:
        case 4:
        cout<<a*0.02;
        break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        cout<<a*0.03;
        case 10:
        cout<<a*0.05
    }
    return 0;
    
}