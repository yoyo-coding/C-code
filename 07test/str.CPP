#include<bits/stdc++.h>
using namespace std;
int main(){
    char a;
    cin>>a;
    if(a<32){
        cout<<"¿ØÖÆ×Ö·û";
    }
    else if(a >= '0' && a <= '9'){
        cout<<"number";
    }
    else if(a >= 'a' && a <= 'z'){
        cout<<"small";
    }
    else if(a >= 'A' && a <= 'Z'){
        cout<<"big";
    }
    else{
        cout<<"#";
    }
    return 0;
    
}