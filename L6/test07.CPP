#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    if(a>=90){
        cout<<"A";
    }
    else if(a>=70 and a<90){
        cout<<"B";
    }
    else if(a>=60 and a<70){
        cout<<"c";
    }
    else{
        cout<<"D";
    }
    return 0;
    
}