#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
struct node{
    int st;
    int ed;
}t[100005];
int tmp;
string p;
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
    int cnt = 0;
    int ptr = -45;
    for(int i = 0;i < n;i++){
        if(t[i].st >= ptr+45){
            cnt++;
            ptr = t[i].ed;
        }
    }
    cout<<cnt;
    return 0;
}1