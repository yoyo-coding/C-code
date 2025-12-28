#include<bits/stdc++.h>
using namespace std;
int main() {
    char s[10000];
    int n;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>s[i];
    }
    for(int i = n;i >= 0;i--){
        cout<<s[i]<<" "; 
    }
    
    return 0;
}