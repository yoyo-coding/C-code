#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    string s;
    bool bin = 1,oct = 1,dec = 1,hex = 1;
    for(int i = 1;i <= n;i++){
        bin = 1,oct = 1,dec = 1,hex = 1;
        
        cin>>s;
        int len  = s.size();
        for(int j = 0;j < len ;j++){
            if(s[j] > '1'){
                bin = 0;
            }
            if(s[j] > '7'){
                oct = 0;
            }
            if(s[j] > '9'){
                dec = 0;
            }
            if(s[j] > 'F'){
                hex = 0;
            }
        }
        cout<<bin<<" "<<oct<<" "<<dec<<" "<<hex<<endl;
    }
    
    return 0;
}