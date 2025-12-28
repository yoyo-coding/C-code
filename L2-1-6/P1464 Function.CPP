#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f[21][21][21];
ll w(ll a, ll b, ll c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }
    if (f[a][b][c] != -1) {
        return f[a][b][c];
    }
    if (a < b && b < c) {
        f[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
    }else{
        f[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
    }
    return f[a][b][c];
}

int main() {
    for(int i = 0; i <= 20; i++){
        for(int j = 0; j <= 20; j++){
            for(int k = 0; k <= 20; k++){
                f[i][j][k] = -1;
            }
        }
    }
    ll a, b, c;
    while (cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        ll result = w(a, b, c);
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<result<<endl;
    }
    return 0;
}