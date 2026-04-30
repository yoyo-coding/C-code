#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct HuffmanNode {
    int weight;
    int type;
    int lc, rc;
    int id;
};

HuffmanNode ht[2005];
priority_queue<int, vector<int>, function<bool(int, int)>> hq([](int a, int b) {
    return ht[a].weight > ht[b].weight;
});
int n, cnt;

void print() {
    if (hq.empty()) return;
    int root = hq.top();
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        cout << ht[idx].weight << " " << ht[idx].type << endl;
        if (ht[idx].lc)
            q.push(ht[idx].lc);
        if (ht[idx].rc)
            q.push(ht[idx].rc);
    }
}

int main() {
    cin >> n;
    cnt = n;
    
    for (int i = 1; i <= n; i++) {
        cin >> ht[i].weight;
        ht[i].type = 1;
        ht[i].lc = ht[i].rc = 0;
        ht[i].id = i;
        hq.push(i);
    }
    
    while (hq.size() > 1) {
        int x = hq.top(); hq.pop();
        int y = hq.top(); hq.pop();
        
        cnt++;
        ht[cnt].weight = ht[x].weight + ht[y].weight;
        ht[cnt].type = 0;
        ht[cnt].lc = x;
        ht[cnt].rc = y;
        ht[cnt].id = cnt;
        
        hq.push(cnt);
    }
    
    print();
    
    return 0;
}