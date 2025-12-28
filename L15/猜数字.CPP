#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int r;
    do{
        cin>>n;
        if(n > r){
            cout<<"猜大了";
        }
        else if(n < r){
            cout<<"猜小了";
        }
        else{
            cout<<"神啊，可不可以让我感受一下";
        }
    }while(r != n)
    return 0;
    
}