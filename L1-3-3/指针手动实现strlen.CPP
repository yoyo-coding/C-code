#include<bits/stdc++.h>
using namespace std;
int strLen(char *p){
    int i = 0;
    while(*p != '\0'){
        i++;
        p++;
    }
    return i;
}
int main(){
    char s[10000];
    cin>>s;
    cout<<strLen(s);
    return 0;
    
}