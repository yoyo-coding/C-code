#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
string num;
int To_DEC(int x,string s){
    ll len = s.length();
    ll tmp = 0,ans = 0;
    if(x >= 10){
        for(ll i = len-1;i >= 0;i--){
            if(s[i] >= 'A' && s[i] <= 'Z')
                ans += (s[i]-'A'+10) * pow(x,tmp);
            else
                ans += (s[i]-'0') * pow(x,tmp);
            tmp++;
        }
    }
    else{
        for(ll i = len-1;i >= 0;i--){
            ans += (s[i]-'0') * pow(x,tmp);
            tmp++;
        }
    }
    return ans;
}
int main(){
    cin>>n;
    
    for(ll i = 0;i < n;i++){
        cin>>k>>num;
        cout<<To_DEC(k,num)<<endl;
    }
    return 0;
    
}