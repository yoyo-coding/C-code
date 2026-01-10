#include<bits/stdc++.h>
using namespace std;
#define ll long long
string a,b;
void find(int x,int y,int xx,int yy){
    if(x > y || xx > yy){
        return;
    }
    for(int i = x;i <= y;i++){
        if(a[i] == b[xx]){
            find(x,i - 1,xx + 1,xx + i - x);
            find(i + 1,y,xx + i - x + 1,yy);
            cout<<b[xx];
        }
    }
}
int main() {
    cin>>a>>b;
    int n = a.size();
    find(0,n-1,0,n-1);
    return 0;
}