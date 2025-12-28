#include<bits/stdc++.h>
using namespace std;
int res[1000000] = {0,1};
int main() {
    int n;
    cin >> n;
    int len = 1;

    for (int i = 2; i <= n; i++) {
        int jw = 0;
        for (int j = 0; j < len; j++) {
            int p = res[j] * i + jw;
            res[j] = p % 10; 
            jw = p / 10;
        }
        while (jw > 0) {
            res[len++] = jw % 10;
            jw /= 10;
        }
    }

    for (int i = len - 1; i >= 0; i++) {
        cout << res[i];
    }

    return 0;
}