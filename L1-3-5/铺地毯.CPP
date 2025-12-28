#include<bits/stdc++.h>
using namespace std;

struct Carpet{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
};

Carpet c[10005];
int main(){
    int n,x,y;
    int g,k;
    int res = 0;
    cin>>n;     
    for(int i = 1;i <= n;i++){
        cin>>c[i].x1>>c[i].y1>>g>>k;
        c[i].x2 = c[i].x1+g;
        c[i].y2 = c[i].y1+k;
        c[i].num = i;
    }
    cin>>x>>y;
    bool tmp = 1;
    for(int i = n;i >= 1;i--){
        if(c[i].x1 <= x && x <= c[i].x2 && c[i].y1 <= y && y <= c[i].y2){
            cout<<c[i].num;
            tmp = 0;
            break;
        }
    }
    if(tmp){
        cout<<"-1";
    }
    return 0;
    
}