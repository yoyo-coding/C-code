#include<bits/stdc++.h>
using namespace std;

int n;
string p;
struct node{
    int st;
    int ed;
}t[250];

bool cmp(const node &a, const node &b){
    return a.st < b.st;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p;
        int h1 = (p[0]-'0')*10 + (p[1]-'0');
        int m1 = (p[2]-'0')*10 + (p[3]-'0');
        int h2 = (p[5]-'0')*10 + (p[6]-'0');
        int m2 = (p[7]-'0')*10 + (p[8]-'0');
        
        t[i].st = h1*60 + m1;
        t[i].ed = h2*60 + m2;
    }
    
    sort(t, t+n, cmp);
    
    int r_ed[250];
    int r_cnt = 0;
    
    for(int i = 0; i < n; i++) {
        int ptr = -1;
        int ptr_t = 0x3f3f3f3f;
        
        for(int j = 0; j < r_cnt; j++) {
            if(r_ed[j] < ptr_t) {
                ptr_t = r_ed[j];
                ptr = j;
            }
        }
        
        if(ptr != -1 && r_ed[ptr] + 10 <= t[i].st) {
            r_ed[ptr] = t[i].ed;
        } else {
            r_ed[r_cnt] = t[i].ed;
            r_cnt++;
        }
    }
    
    cout << r_cnt;
    return 0;
}