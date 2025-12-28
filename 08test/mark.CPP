#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    switch(a/10){
        case 10:
        case 9:
            cout<<"A";
            break;
        case 8:
        case 7:
            cout<<"B";
            break;
        case 6:
            cout<<"C";
            break;
        default:
            cout<<"D";


    }
    return 0;
    
}