#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    string w;
    int apear = 0;
}word[500];
bool cmp(node a, node b) {
    if (a.apear != b.apear) return a.apear > b.apear;
    return a.w < b.w;
}
int main() {
    freopen("frequency.in", "r", stdin);
    freopen("frequency.out", "w", stdout);
    string s;
    int cnt = 0;
    map<string, int> mp;
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (c >= 'a' && c <= 'z') {
            s += c;
        } else if (!s.empty()) {
            if (mp.find(s) == mp.end()) {
                word[cnt].w = s;
                cnt++;
            }
            mp[s]++;
            s.clear();
        }
    }
    if (!s.empty()) {
        if (mp.find(s) == mp.end()) {
            word[cnt].w = s;
            cnt++;
        }
        mp[s]++;
    }
    int k;
    cin>>k;
    for (int i = 0; i < cnt; i++) {
        word[i].apear = mp[word[i].w];
    }
    sort(word, word + cnt, cmp);
    for (int i = 0; i < k; i++) {
        cout<<word[i].w<<endl;
    }
    return 0;
}