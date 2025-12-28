#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    while(b){
        int tmp =a;
        a = b;
        b = tmp%b;
    }
    return a;
}
int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int main(){
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    int tmp = a*b;
    for(int p = a;p <= b;p++){
        if(gcd(p,tmp/p) == lcm(p,tmp/p) == b){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}