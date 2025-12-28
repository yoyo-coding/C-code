#include<bits/stdc++.h>
using namespace std;
int main(){
    char s[85];
    int n;
    cin.getline(s,85);
    n = strlen(s);
    for(int i = 0;i < n;i++){
        if(s[i] >= 'A' && s[i] <= 'Y' || s[i] >= 'a' && s[i] <= 'y'){
            s[i] += 1;
        }
        else{
            if(s[i] == 'Z')
                s[i] = 'A';
            if(s[i] == 'z')
                s[i] = 'a';
        }
        cout<<s[i];
    }
    return 0;
    
}