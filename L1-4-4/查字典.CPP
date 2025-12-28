#include<bits/stdc++.h>
using namespace std;
int main() {
    map<string,int> d;
    string w,fs;
    int n,f,p;
    cin>>n;
    for(int i = 0 ;i < n;i++){
        cin>>w>>p;
        d[w] = p;
    }
    cin>>f;
    for(int i = 0 ;i < n;i++){
        cin>>fs;
        cout<<d[fs]<<endl;
    }
    return 0;
}