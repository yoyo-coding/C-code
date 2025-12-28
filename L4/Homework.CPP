#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    if(a%b == 0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    //-------我是分割线--------

    int a,b,c;
    cin>>a>>b;
    c = a-110;
    if(b >= (c+5)){
        cout<<"fat";
    }
    else{
        cout<<"normal"
    }

    //-------我是分割线--------

    int i;
    cin >> i;
    if (i%2==0){
        cout << "'even";
    }
    if (i%2 !=0){
        cout << "odd";
    }

    //-------我是分割线--------
    int a,w,b;
    cin>>a;
    w = a/1;
    b = 23+27+a/3;
    if(w > b){
        cout<<"Bike";
    }
    if(b > w){
        cout<<"Work";
    }
    else{
        cout<<"All";
    }


    return 0;
    
}