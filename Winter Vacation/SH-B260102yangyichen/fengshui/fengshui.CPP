#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 100005;
int f[N*3];
int n,m;
char c;
int ans = 0;

int fd(int x) {
    if(f[x] == x) return x;
    return f[x] = fd(f[x]);
}

void mg(int x,int y) {
    int fx = fd(x);
    int fy = fd(y);
    if(fx != fy) {
        f[fx] = fy;
    }
}

int main() {
    freopen("fengshui.in","r",stdin);
    freopen("fengshui.out","w",stdout);
    
    cin>>n>>m;
    
    for(int i = 0;i < 3*n;i++) {
        f[i] = i;
    }
    
    for(int i = 1;i <= m;i++){
        int x,y;
        cin>>c>>x>>y;
        
        if(x == y) {
            ans++;
            continue;
        }
        
        x--; y--;
        
        bool cf = false;
        
        if(c == 'k') {
            if(fd(x) == fd(y)) cf = true;
            if(fd(x+n) == fd(y+2*n)) cf = true;
            if(fd(x+2*n) == fd(y+n)) cf = true;
            
            if(!cf) {
                mg(x+n, y+2*n);
                mg(x+2*n, y+n);
            }
        }
        else if(c == 's') {
            if(fd(x) == fd(y)) cf = true;
            if(fd(x+n) == fd(y)) cf = true;
            if(fd(x) == fd(y+2*n)) cf = true;
            if(fd(x+n) == fd(y+2*n)) cf = true;
            if(fd(x+2*n) == fd(y)) cf = true;
            if(!cf) {
                mg(x+n, y);
                mg(x, y+2*n);
            }
        }
        
        if(cf) {
            ans++;
        }
    }
    
    cout<<ans;
    return 0;
}