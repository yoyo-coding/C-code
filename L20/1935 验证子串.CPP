#include<bits/stdc++.h>
using namespace std;
//s1 bigger than s2
bool  is_Substr(char s1[],char s2[]){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int flen = len1-len2;
    for(int i = 0;i <= flen;i++){
        bool issame = true;
        for(int j = 0;j < len2;j++){
            if(s1[i+j] != s2[j]){
                issame = false;
                break;
            }
        }
        if(issame)
        return true;
    }
    return false;
}
int main(){
    char a[205];
    char b[205];
    cin>>a;
    cin>>b;
    if(strlen(a) > strlen(b)){
        if(is_Substr(a,b) == 1){
            cout<<b<<" is substring of "<<a;
        }
        else{
            cout<<"No substring";
        }
    }
    else{
        if(is_Substr(b,a) == 1){
            cout<<a<<" is substring of "<<b;
        }
        else{
            cout<<"No substring";
    	}
	}
    return 0;
    
}