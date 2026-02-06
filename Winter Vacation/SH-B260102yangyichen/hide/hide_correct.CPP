#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("hide.in","r",stdin);
    freopen("hide.out","w",stdout);
    
    int n;
    cin>>n;
    
    vector<int> a, b;
    
    for(int i = 0; i < n; i++){
        char c;
        int v;
        cin>>c>>v;
        if(c == 'L'){
            a.push_back(v);
        } else {
            b.push_back(v);
        }
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int r = n;
    int x = a.size();
    int y = b.size();
    
    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++){
            int f = 1;
            
            if(i > 0 && j > 0){
                int p = a[i - 1];
                int q = b[y - j];
                if(p < q) f = 0;
            }
            
            if(f){
                int s = (x - i) + (y - j);
                if(s < r) r = s;
            }
        }
    }
    
    cout<<r<<endl;
    
    return 0;
}