#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    if(a == 5 or a == 0){
        cout<<"monday";
    }
    else if(a == 1 or a == 6){
        cout<<"tuesday";
    }
    else if(a == 2 or a == 7){
        cout<<"wednesday";
    }
    else if(a == 3 or a == 8){
        cout<<"thursday";
    }
    else if(a == 4 or a == 9){
        cout<<"friday";
    }
    return 0;
    
}