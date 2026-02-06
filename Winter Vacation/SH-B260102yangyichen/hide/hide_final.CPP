#include<bits/stdc++.h>
using namespace std;
int n;
int l[1005], g[1005];
int nl, ng;

int main(){
    freopen("hide.in","r",stdin);
    freopen("hide.out","w",stdout);
    
    cin>>n;
    nl = ng = 0;
    for(int i = 0; i < n; i++){
        char c;
        int v;
        cin>>c>>v;
        if(c == 'L') l[nl++] = v;
        else g[ng++] = v;
    }
    
    for(int i = 0; i < nl-1; i++){
        for(int j = 0; j < nl-1-i; j++){
            if(l[j] > l[j+1]){
                int tmp = l[j];
                l[j] = l[j+1];
                l[j+1] = tmp;
            }
        }
    }
    
    for(int i = 0; i < ng-1; i++){
        for(int j = 0; j < ng-1-i; j++){
            if(g[j] > g[j+1]){
                int tmp = g[j];
                g[j] = g[j+1];
                g[j+1] = tmp;
            }
        }
    }
    
    int ans = n;
    
    for(int i = 0; i <= nl; i++){
        for(int j = 0; j <= ng; j++){
            bool ok = 1;
            if(i > 0 && j > 0){
                int maxn = l[i-1];
                int minn = g[ng-j];
                if(maxn < minn) ok = 0;
            }
            
            if(ok){
                int remove = (nl - i) + (ng - j);
                ans = min(ans, remove);
            }
        }
    }
    
    cout<<ans;
    return 0;
}