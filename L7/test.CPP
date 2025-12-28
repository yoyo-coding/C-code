#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    char c;
    cin>>a>>c>>b;
    if(a == 0 or b == 0){
        cout<<" 0 is not aloud";
    }
    else{
        switch(c){
            case '+':
                cout<<a+b;
                break;
            case '-':
                cout<<a-b;\
                break;
            case '*':
                cout<<a*b;
                break;
            case '/':
                cout<<a/b;
                break;
            case '%':
                cout<<a%b;
                break;
        }
    }
    return 0;
    
}