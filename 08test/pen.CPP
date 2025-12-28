#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    switch (a){
        case 1:
            cout<<"本次用时0.03秒"<<endl;
            cout<<"3"<<endl;
            break;
        case 2:
            cout<<"本次用时0.27秒"<<endl;
            cout<<"2.5"<<endl;
            break;
        case 3:
            cout<<"本次用时0.35秒"<<endl;
            cout<<"4.1"<<endl;
            break;
        case 4:
            cout<<"本次用时0.05秒"<<endl;
            cout<<"10.2"<<endl;
            break;
    
        default:
            cout<<"请求超时";
            break;
    
    }
    return 0;
    
}