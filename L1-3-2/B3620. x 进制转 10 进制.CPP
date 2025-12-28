#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int x;
    cin>>x;
    cin>>s;
    int len = s.length();
    int tmp = 0,ans = 0;
    if(x >= 10){
        for(int i = len-1;i >= 0;i--){
            if(s[i] >= 'A' && s[i] <= 'Z')
                ans += (s[i]-'A'+10) * pow(x,tmp);
            else
                ans += (s[i]-'0') * pow(x,tmp);
            tmp++;
        }
    }
    else{
        for(int i = len-1;i >= 0;i--){
            ans += (s[i]-'0') * pow(x,tmp);
            tmp++;
        }
    }
    cout<<ans;
    return 0;
    
}