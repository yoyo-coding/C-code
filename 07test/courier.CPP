#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    if(a <= 10){
        cout<<fixed<<setprecision(2)<<a*0.8+0.2;
    }
    else if(a <= 20){
        cout<<fixed<<setprecision(2)<<10*0.8+(a-10)*0.75+0.2;
    }
    else if(a <= 30){
        cout<<fixed<<setprecision(2)<<10*0.8+(a-10)*0.75+(a-20)*0.7+0.2;
    }
    else{
        cout<<"Fail";
    }
    return 0;
    
}