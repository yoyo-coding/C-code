#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    bool k;
    cin >> t >> k;
    
    while(t--) {
        int n;
        string target;
        cin >> n >> target;
        
        string input = "";
        int flips = 0;
        
        for(int i = n-1; i >= 0; i--) {
            char actual_char;
            if(flips % 2 == 0) {
                actual_char = target[i];
            } else {
                actual_char = (target[i] == 'M') ? 'O' : 'M';
            }
            
            input = actual_char + input;
            if(actual_char == 'O') {
                flips++;
            }
        }
        
        string result = "";
        for(int i = 0; i < n; i++) {
            if(input[i] == 'M') {
                result += 'M';
            } else {
                for(int j = 0; j < result.length(); j++) {
                    result[j] = (result[j] == 'M') ? 'O' : 'M';
                }
                result += 'O';
            }
        }
        
        if(result == target) {
            cout << "YES" << endl;
            if(k) {
                cout << input << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}