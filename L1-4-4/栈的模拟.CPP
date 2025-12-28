#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[5],n;
    int p = 0;
    string c;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>c;
        if(c == "P"){
            cin>>a[p];
            p++;
        }else if(c == "O"){
            if(p >= 0){
               p--;
            }
        }else if(c == "A"){
            if(p < 0){
                cout<<"E"<<endl;
            }else if(p >= 0){
                cout<<a[p-1]<<endl;
            }
        }
    }
    return 0;
}