#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Op {
    int type;
    int x, y, z;
};

void remove_from_vec(vector<int>& v, int val) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == val) {
            for (int j = i; j < v.size() - 1; ++j) {
                v[j] = v[j + 1];
            }
            v.pop_back();
            break;
        }
    }
}

void remove_from_pair_vec(vector<pair<int, int>>& v, int r, int c) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].first == r && v[i].second == c) {
            v[i] = v[v.size() - 1];
            v.pop_back();
            break;
        }
    }
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    string t;
    cin >> t;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    
    vector<vector<int>> p1(26);
    vector<vector<pair<int, int>>> p2(26);
    
    for (int k = 0; k < m; ++k) {
        p1[s[0][k] - 'a'].push_back(k);
    }
    
    for (int i = 1; i < n; ++i) {
        for (int k = 0; k < m; ++k) {
            int c = s[i][k] - 'a';
            p2[c].push_back({i, k});
        }
    }
    
    vector<Op> ops;
    
    for (int j = 0; j < m; ++j) {
        int tg = t[j] - 'a';
        if (s[0][j] - 'a' == tg) {
            continue;
        }
        
        vector<int> v1;
        vector<int>& vt = p1[tg];
        for (int i = 0; i < vt.size(); ++i) {
            if (vt[i] >= j) v1.push_back(vt[i]);
        }
        p1[tg] = v1;
        
        if (!p1[tg].empty()) {
            int k = p1[tg][p1[tg].size() - 1];
            ops.push_back({1, 1, j + 1, k + 1});
            
            char cj = s[0][j];
            char ck = s[0][k];
            s[0][j] = ck;
            s[0][k] = cj;
            
            remove_from_vec(p1[tg], k);
            int c_j = cj - 'a';
            remove_from_vec(p1[c_j], j);
            if (k >= j) {
                p1[c_j].push_back(k);
            }
            
            continue;
        }
        
        int fi = -1;
        for (int i = 1; i < n; ++i) {
            if (s[i][j] - 'a' == tg) {
                fi = i;
                break;
            }
        }
        
        if (fi != -1) {
            ops.push_back({2, 1, fi + 1, j + 1});
            
            char cj = s[0][j];
            s[0][j] = t[j];
            s[fi][j] = cj;
            
            int c_j = cj - 'a';
            remove_from_vec(p1[c_j], j);
            remove_from_pair_vec(p2[tg], fi, j);
            p2[c_j].push_back({fi, j});
            
            continue;
        }
        
        pair<int, int> pk = {-1, -1};
        vector<pair<int, int>>& vp = p2[tg];
        for (int i = 0; i < vp.size(); ++i) {
            if (vp[i].second >= j) {
                pk = vp[i];
                vp[i] = vp[vp.size() - 1];
                vp.pop_back();
                break;
            }
        }
        
        if (pk.first != -1) {
            int i = pk.first;
            int k = pk.second;
            
            ops.push_back({2, 1, i + 1, k + 1});
            
            char c0k = s[0][k];
            char cik = s[i][k];
            s[0][k] = cik;
            s[i][k] = c0k;
            
            int c_0k = c0k - 'a';
            remove_from_vec(p1[c_0k], k);
            p1[tg].push_back(k);
            p2[c_0k].push_back({i, k});
            
            ops.push_back({1, 1, j + 1, k + 1});
            
            char c0j = s[0][j];
            char c0kn = s[0][k];
            
            s[0][j] = c0kn;
            s[0][k] = c0j;
            int c_0j = c0j - 'a';
            remove_from_vec(p1[c_0j], j);
            if (k >= j) p1[c_0j].push_back(k);
            remove_from_vec(p1[tg], k);
        }
    }
    
    cout << ops.size() << endl;
    for (int i = 0; i < ops.size(); ++i) {
        const Op& op = ops[i];
        cout << op.type << " " << op.x << " " << op.y << " " << op.z << endl;
    }
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}