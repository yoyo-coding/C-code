#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,n;
    string b,c,d,e;
    cin>>n;
    while(n--){
        cin>>a>>b>>c>>d>>e;
        if(b[0] == 'k' && (e == "m" || e == "g")){
            cout<<a<<' '<<b<<' '<<c<<' '<<a*1000<<' '<<e<<endl;
        }
        else if(b == "m"||b == "g"){
            cout<<a<<' '<<b<<' '<<c<<' '<<a*1000<<' '<<e<<endl;
        }
        else{
            cout<<a<<' '<<b<<' '<<c<<' '<<a*1000*1000<<' '<<e<<endl;
        }
    
    }
    
    
    return 0;
}