#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int len = s.length();
    int tmp = 0,ans = 0;
    for(int i = len-1;i >= 0;i--){
        ans += (s[i]-'0') * pow(2,tmp);
        tmp++;

    }
    cout<<ans;
    return 0;
    
}