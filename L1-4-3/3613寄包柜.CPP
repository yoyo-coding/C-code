#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> a[100010];
    int n,q,p,b,c,d;
    cin>>n>>q;
    while(q--){
        cin>>p;
        if(p == 1){
            cin>>b>>c>>d;
            if(a[b].size() < c+1){
                a[b].resize(c+1);
            }
            a[b][c] = d;
        }
        else if(p == 2){
            cin>>b>>c;
            cout<<a[b][c]<<endl;
        }
    }
    
    return 0;
}