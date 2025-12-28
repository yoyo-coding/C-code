#include<bits/stdc++.h>
using namespace std;
int t,n;
string s[10005];
int main() {
    cin>>t;
    for(int z = 0;z < t;z++){
        cin>>n;
        string tmp = "";
        for(int i = 0;i < n;i++){
            cin>>s[i];
        }
        sort(s,s+n);
        for(int i = 0;i < n;i++){
            tmp += s[i];
        }
        bool flag = true;
        for(int i = 1;i < tmp.size();i++){
            if(!(tmp[i]>=tmp[i-1])){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    
    return 0;
}