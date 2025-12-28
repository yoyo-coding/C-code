#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    for(int p = 1;p <= t;p++){
        int n;
        cin>>n;
        int a[100000] = {};
        for(int i = 0;i < n;i++){
            cin>>a[i];
        }
        bool flag = 1;
        for(int i = 0;i < n;i++){
            flag = 1;
            for(int j = 0;j < n;j++){
                if(a[i] % a[j] != 0){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                cout<<"Yes"<<endl;
                break;
            }
        }
        if(!flag){
            cout<<"No"<<endl;
        }
    }
    
    return 0;
}