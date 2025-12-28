#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    switch(a/10){
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            cout<<"10";
            break;
        case 11:
            cout<<"30";
            break;
        case 12:
            cout<<"50";
            break;
        default:
            cout<<"80";

    }
    return 0;
    
}