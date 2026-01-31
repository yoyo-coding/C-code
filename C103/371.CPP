#include<bits/stdc++.h>
using namespace std;

struct node {
    int pos, radius;
    int left, right;
};

bool cmp(const node &a, const node &b) {
    if (a.left != b.left) return a.left < b.left;
    return a.right > b.right;
}

int main() {
    int L, m;
    cin>>L>>m;
    
    node towers[10005];
    for (int i = 0; i < m; i++) {
        cin>>towers[i].pos>>towers[i].radius;
        towers[i].left = towers[i].pos - towers[i].radius;
        towers[i].right = towers[i].pos + towers[i].radius;
    }
    
    sort(towers, towers + m, cmp);
    
    if (m == 0 || towers[0].left > 0) {
        return 0;
    }
    
    int ptr = 0;
    int cnt = 0;
    int i = 0;
    
    while (ptr < L && i < m) {
        if (towers[i].left > ptr) {
            cout<<"Impossible"<<endl;
            return 0;
        }
        
        int max_right = ptr;
        while (i < m && towers[i].left <= ptr) {
            if (towers[i].right > max_right) {
                max_right = towers[i].right;
            }
            i++;
        }
        
        if (max_right <= ptr) {
            cout<<"Impossible"<<endl;
            return 0;
        }
        
        ptr = max_right;
        cnt++;                  
        
        i--;
    }
    
    if (ptr >= L) {
        cout<<cnt<<endl;
    } else {
        cout<<"Impossible"<<endl;
    }
    
    return 0;
}