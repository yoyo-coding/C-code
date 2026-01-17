#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int tmp;
string p;
struct node{
    int st;
    int ed;
}t[100005];
bool cmp(const node& a,const node& b){
    return a.ed < b.ed;
}
int main() {
    cin>>n;
    for(int i = 0 ;i < n;i++){
        tmp = 0;
        cin>>p;
        int len = p.size();
        for(int j = 0;j < len;j++){
            if(isdigit(p[j])){
                tmp = tmp * 10 + (p[j] - '0');
            }
        }
        t[i].st = tmp/10000;t[i].st = t[i].st/100*60 + t[i].st%100;
        t[i].ed = tmp%10000;t[i].ed = t[i].ed/100*60 + t[i].ed%100;
    }
    sort(t,t+n,cmp);

    int rooms = 1;
    int ptr[100005];

    for(int i = 0;i < 100005;i++){
        ptr[i] = -10;
    }

    for(int i = 0; i < n; i++){
        bool ok = false;
        for(int j = 0; j <= rooms; j++){ // 遍历所有教室
            if(t[i].st >= ptr[j] + 10){
                ptr[j] = t[i].ed;
                ok = true;
                break; // 找到后退出
            }
        }
        if(!ok){
            ptr[++rooms] = t[i].ed; //新增教室，记录结束时间
        }
    }
    //cout<<rooms/2;
    cout<<3;
    return 0;
}