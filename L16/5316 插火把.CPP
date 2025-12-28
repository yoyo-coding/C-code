#include<bits/stdc++.h>
using namespace std;
int main(){
    char a[105][105];
    int n,m,x,y;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            a[i][j] = 'M';
        }
    }
    for(int i = 1;i <= m;i++){
        cin>>x>>y;
        a[x][y] = 'F';
        for(int j = 1;j <= n;j++){
            if(a[x][j] == 'F'){
                continue;
            }
            a[x][j] = 'L';
        }
        for(int j = 1;j <= n;j++){
            if(a[j][y] == 'F'){
                continue;
            }
            a[j][y] = 'L';
        }
        a[x][y] = 'F';
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
    
}