#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
void cmb(vector<int>& num, int ind, int k, int sum, int& cnt) {
    if (k == 0) {
        if (isPrime(sum)) {
            cnt++;
        }
        return;
    }
    if (ind >= num.size()) {
        return;
    }
    cmb(num, ind + 1, k - 1, sum + num[ind], cnt);
    cmb(num, ind + 1, k, sum, cnt);
}

int main() {
    int n, k;
    cin>>n>>k;
    
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin>>num[i];
    }
    
    int cnt = 0;
    cmb(num, 0, k, 0, cnt);
    
    cout<<cnt<<endl;
    
    return 0;
}