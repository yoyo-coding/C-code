#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct trans{
    string a;
    string b;
}f[205];

int n;
map<string, string> dict;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> f[i].a >> f[i].b;
        dict[f[i].a] = f[i].b;
    }
    string s;
    cin >> s;
    string word = "";
    string result = "";
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        if(c >= 'a' && c <= 'z') {
            word += c;
        } else {
            if(word != "") {
                if(dict.find(word) != dict.end()) {
                    result += dict[word];
                } else {
                    result += "UNK";
                }
                word = "";
            }
            result += c;
        }
    }
    if(word != "") {
        if(dict.find(word) != dict.end()) {
            result += dict[word];
        } else {
            result += "UNK";
        }
    }
    
    cout << result << endl;
    return 0;
}