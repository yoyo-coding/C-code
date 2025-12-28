#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;1
    int len = s.length();
    int tmp = 0,ans = 0;
    for(int i = len-1;i >= 0;i--){
        if(s[i] >= 'A' && s[i] <= 'Z')
            ans += (s[i]-'A'+10) * pow(16,tmp);
        else
            ans += (s[i]-'0') * pow(16,tmp);
        tmp++;
    }
    cout<<ans;
    return 0;
    
}