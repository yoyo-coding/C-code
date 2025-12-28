#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int b = 1000000;
    int minR = -1, minC = -1;
    // 找到最小值及位置
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] < b) {
                b = a[i][j];
                minR = i;
                minC = j;
            }
        }
    }
    // 输出最小值及位置
    cout << b << " " << minR + 1 << " " << minC + 1 << endl;
    return 0;
    
}