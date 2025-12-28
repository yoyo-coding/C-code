#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n][n];
    
    // 初始化矩阵为0
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = 0;
        }
    }
    
    // 将1放在第一行的中间
    int x = 0, y = n / 2;
    a[x][y] = 1;
    
    // 从2开始填入数字
    for(int i = 2; i <= n * n; i++){
        int nx = x, ny = y;
        
        // 按规则确定下一个位置
        if(x == 0 && y != n - 1){
            nx = n - 1;
            ny = y + 1;
        }
        else if(y == n - 1 && x != 0){
            nx = x - 1;
            ny = 0;
        }
        else if(x == 0 && y == n - 1){
            nx = x + 1;
            ny = y;
        }
        else{
            nx = x - 1;
            ny = y + 1;
            if(a[nx][ny] != 0){
                nx = x + 1;
                ny = y;
            }
        }
        
        // 填入数字
        a[nx][ny] = i;
        x = nx;
        y = ny;
    }
    
    // 输出矩阵
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}