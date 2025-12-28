#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    switch(a){
        case 1:
            cout<<10;
            break;
        case 2:
            cout<<10+15;
            break;
        case 3:
            cout<<25+20;
            break;
        default:
            cout<<45+(a-3)*20;

    }
    return 0;
    
}