#include<bits/stdc++.h>
using namespace std;
int calcu(int a,char b,int c){
    if(b =='+'){
        return a+c;
    }
    else if(b == '-'){
        return a-c;
    }
    else if(b == '*'){
        return a*c;
    }
    else if(b == '/'){
        return a/c;
    }
}
int main(){
    int a,b;
    char f;
    cin>>a>>f>>b;
    cout<<calcu(a,f,b);
    return 0;
    
}