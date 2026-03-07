#include<bits/stdc++.h>
using namespace std;
#define ll long long

int digitSum(ll num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int transformDigit(int digit) {
    int result = digit * 7;
    while (result > 9) {
        result = digitSum(result);
    }
    return result;
}

bool isLuckyNumber(ll num) {
    string str = to_string(num);
    string transformed = "";
    
    for (int i = str.length() - 1; i >= 0; i--) {
        int pos = str.length() - i;
        int digit = str[i] - '0';
        
        if (pos % 2 == 1) {
            transformed = to_string(transformDigit(digit)) + transformed;
        } else {
            transformed = to_string(digit) + transformed;
        }
    }
    ll transformedNum = stoll(transformed);
    int sum = digitSum(transformedNum);
    
    return (sum % 8 == 0);
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        if (isLuckyNumber(num)) {
            cout << "T" << endl;
        } else {
            cout << "F" << endl;
        }
    }
    
    return 0;
}