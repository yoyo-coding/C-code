#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c=0;
    cin>>a>>b;
    switch(b){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            c = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            c = 30;
            break;
        case 2:
            c = a%4 == 0 and a%100 != 0 or a%400 == 0?29:28;
            break;
        default:
            cout<<"error";
    }
    cout<<endl<<c;
    return 0;
    
}