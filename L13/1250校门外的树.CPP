#include<bits/stdc++.h>
using namespace std;

int main() {
    int l, m;
    cin >> l >> m;

    // 初始化数组，标记哪些树要除
    int removed[l + 1] = {0};

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        // 标记区间内的所有树
        for (int j = u; j <= v; ++j) {
            removed[j] = 1;
        }
    }

    // 剩余的树数量
    int reTrees = 0;
    for (int i = 0; i <= l; ++i) {
        if (removed[i] == 0) {
            reTrees++;
        }
    }

    cout << reTrees << endl;

    return 0;
}