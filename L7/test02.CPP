#include<bits/stdc++.h>
using namespace std;
int main(){
    char a;
    cin>>a;
    switch(a){
        case 'A':
            cout<<8000+500;
            break;
        case 'B':
            cout<<8000+200;
            break;
        case 'C':
            cout<<8000+0;
            break;
        case 'D':
            cout<<8000-200;
            break;
        case 'E':
            cout<<8000-500;
            break;
        default:
            cout<<"error";
    }
    return 0;
    
}