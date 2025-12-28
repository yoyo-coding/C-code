#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isSimilar(string a, string b) {
    int len_a = a.length();
    int len_b = b.length();
    if (abs(len_a - len_b) > 1) {
        return false;
    }
    if (a == b) {
        return true;
    }
    if (len_a == len_b) {
        int diff_count = 0;
        for (int i = 0; i < len_a; i++) {
            if (a[i] != b[i]) {
                diff_count++;
                if (diff_count > 1) {
                    return false;
                }
            }
        }
        return true;
    }
    if (len_a == len_b + 1) {
        int i = 0, j = 0;
        bool found_diff = false;
        while (i < len_a && j < len_b) {
            if (a[i] != b[j]) {
                if (found_diff) {
                    return false;
                }
                found_diff = true;
                i++;
            } else {
                i++;
                j++;
            }
        }
        return true;
    }
    if (len_b == len_a + 1) {
        int i = 0, j = 0;
        bool found_diff = false;
        while (i < len_a && j < len_b) {
            if (a[i] != b[j]) {
                if (found_diff) {
                    return false;
                }
                found_diff = true;
                j++;
            } else {
                i++;
                j++;
            }
        }
        return true;
    }
    
    return false;
}

int main() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        string a, b;
        cin >> a >> b;
        
        if (isSimilar(a, b)) {
            cout << "similar" << endl;
        } else {
            cout << "not similar" << endl;
        }
    }
    
    return 0;
}