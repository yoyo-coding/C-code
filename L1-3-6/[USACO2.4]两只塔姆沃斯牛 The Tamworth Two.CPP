#include<bits/stdc++.h>
using namespace std;
char a[20][20];
int cx,cy,fx,fy;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int main(){
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            cin >> a[i][j];
            if(a[i][j] == 'C'){
                cx = i;
                cy = j;
            }
            if(a[i][j] == 'F'){
                fx = i;
                fy = j;
            }

        }
    }
    int cd = 0,fd = 0,time = 1e5,cnt = 0;
    while(cnt <= time){
        if(cx == fx && cy == fy){
            break;
        }
        cx = cx + dir[cd][0];
        cy = cy + dir[cd][1];
        if(a[cx][cy] == '*' || cx < 0 || cy < 0 || cx > 9 || cy > 9){
            cx = cx - dir[cd][0];
            cy = cy - dir[cd][1];
            if(cd == 3){
                cd = 0;
            }
            else{
                cd++;
            }
        }
        fx = fx + dir[fd][0];
        fy = fy + dir[fd][1];
        if(a[fx][fy] == '*' || fx < 0 || fy < 0 || fx > 9 || fy > 9){
            fx = fx - dir[fd][0];
            fy = fy - dir[fd][1];
            if(fd == 3){
                fd = 0;
            }
            else{
                fd++;
            }
        }
        cnt++;
    }
    if(cnt > time)	cout<<"0";
	else cout<<cnt;
    return 0;
    
}