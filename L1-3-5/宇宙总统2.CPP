#include<bits/stdc++.h>
using namespace std;
struct Cnd {
    string n;
    int v;
};

bool cmp(const Cnd& a, const Cnd& b) {
    if (a.v != b.v) {
        return a.v > b.v;
    }
    return a.n > b.n;
}

int main() {
    int n;
    cin >> n;

    Cnd cnd[1000];
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        string nm;
        cin >> nm;
        bool fnd = false;

        for (int j = 0; j < cnt; ++j) {
            if (cnd[j].n == nm) {
                cnd[j].v++;
                fnd = true;
                break;
            }
        }

        if (!fnd) {
            cnd[cnt].n = nm;
            cnd[cnt].v = 1;
            cnt++;
        }
    }

    sort(cnd, cnd + cnt, cmp);

    for (int i = 0; i < cnt; ++i) {
        cout << cnd[i].n << " " << cnd[i].v << endl;
    }

    return 0;
}