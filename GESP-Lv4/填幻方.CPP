#include<bits/stdc++.h>
using namespace std;
#define ll long long
int m[25][25];
int n,x,y;

int main() {
    cin>>n;
    x = 1;
    y = n/2 + 1;
    m[x][y] = 1;
    
    for(int i = 2; i <= n*n; i++){
        int mx = x, my = y;
        mx = x - 1;
        my = y + 1;
        if(mx < 1) mx = n;
        if(my > n) my = 1;
        if(m[mx][my] != 0){
            mx = x + 1;
            my = y;
            if(mx > n) mx = 1;
        }
        m[mx][my] = i;
        x = mx;
        y = my;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<m[i][j];
            if(j != n) cout<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}