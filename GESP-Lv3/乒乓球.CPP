#include<bits/stdc++.h>
using namespace std;
int main() {
    string a;
    char tmp;
    int p1s = 0,p2s = 0;
    while(cin>>tmp){
        a += tmp;
        if(tmp == 'E') 
            break;
    }
    int len = a.size();
    for(int i = 0;i < len;i++){
        if((p1s >= 11 || p2s >= 11) && abs(p1s - p2s) >= 2){
            cout<<p1s<<":"<<p2s<<endl;
            p1s = 0;
            p2s = 0;
        }
        if(a[i] == 'E'){
            cout<<p1s<<":"<<p2s<<endl;
            p1s = 0;
            p2s = 0;
        }
        if(a[i] == 'W'){
            p1s++;
        }else if(a[i] == 'L'){
            p2s++;
        }
    }
    cout<<endl;
    for(int i = 0;i < len;i++){
        if((p1s >= 21 || p2s >= 21) && abs(p1s - p2s) >= 2 ){
            cout<<p1s<<":"<<p2s<<endl;
            p1s = 0;
            p2s = 0;
        }
        if(a[i] == 'E'){
            cout<<p1s<<":"<<p2s<<endl;
            p1s = 0;
            p2s = 0;
        }
        if(a[i] == 'W'){
            p1s++;
        }else if(a[i] == 'L'){
            p2s++;
        }
    }
    
    return 0;
}