#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

void solve() {
    string x;
    cin >> x;
    bool has_non_binary = false;
    for (char c : x) {
        if (c != '0' && c != '1') {
            has_non_binary = true;
            break;
        }
    }
    string extracted = "";
    for (char c : x) {
        if (c == '0' || c == '1') {
            extracted += c;
        }
    }
    
    if (extracted.empty()) {
        cout << (has_non_binary ? 2 : 1) << "\n";
        return;
    }
    size_t first_one = extracted.find('1');
    if (first_one == string::npos) {
        cout << (has_non_binary ? 1 : 0) << "\n";
        return;
    }
    extracted = extracted.substr(first_one);
    long long binary_val = 0;
    long long ones = 0;
    for (char c : extracted) {
        binary_val = (binary_val * 2) % MOD;
        if (c == '1') {
            binary_val = (binary_val + 1) % MOD;
            ones++;
        }
    }
    long long ans = (binary_val + ones - 1) % MOD;
    if (has_non_binary) {
        ans = (ans + 1) % MOD;
    }
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}