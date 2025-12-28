#include<bits/stdc++.h>
using namespace std;
int main() {
    set<int> s;
    int a[9];
    int n,x;
    cin>>n;
    for(int i = 1; i <= n; i++) {
        cin>>x;
        a[i] = x;
        s.insert(x);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                for(int l = 1; l <= n; l++) {
                    for(int m = 1; m <= n; m++) {
                        int n1 = a[i]*100 + a[j]*10 + a[k];
                        int n2 = n1*
                    }
                }
            }
        }
    }
    return 0;
}