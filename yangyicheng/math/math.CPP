#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,tmp,t;
int main() {
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
    cin>>t;
    for(int i = 0;i < t;i++){
        cin>>a>>b;
        if(a == b){
            cout<<0<<endl;
        }
        if(a > b){
            if((a-b)%2 == 0){
                cout<<1<<endl;
            }
            else{
                cout<<2<<endl;
            }
        }
        if(a<b){
            if((b-a)%2 == 1){
                cout<<1<<endl;
            }
            else if((b-a)%4 == 0){
                cout<<3<<endl;
            }
            else{
                cout<<2<<endl;
            }
            
        }
    }
    
    return 0;
}