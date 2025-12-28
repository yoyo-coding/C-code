#include<bits/stdc++.h>
using namespace std;
//# 是墙
//. 是空地
//F 是火
//J 是人
//人每次可以向四个方向移动一格
//火每次可以向四个方向都蔓延一格
int r,c;
char a[1005][1005];
struct node{
    int x,y,step;
    bool isFire;
}
queue<node> q;
void bfs(){
    
}
int main() {
    cin>>r>>c;
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            cin>>a[i][j];
        }
    }
    bfs();
    return 0;
}