#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<int> maxq(n);
    vector<int> minq(n);
    int max_h = 0, max_t = 0;
    int min_h = 0, min_t = 0;
    
    vector<int> res;
    
    for (int i = 0; i < n; i++) {
        while (max_h < max_t && maxq[max_h] <= i - k) {
            max_h++;
        }
        while (min_h < min_t && minq[min_h] <= i - k) {
            min_h++;
        }
        
        while (max_h < max_t && x[maxq[max_t-1]] <= x[i]) {
            max_t--;
        }
        maxq[max_t++] = i;
        while (min_h < min_t && x[minq[min_t-1]] >= x[i]) {
            min_t--;
        }
        minq[min_t++] = i;
        
        if (i >= k - 1) {
            int max_val = x[maxq[max_h]];
            int min_val = x[minq[min_h]];
            res.push_back(max_val - min_val);
        }
    }
    
    for (int i = 0; i < res.size(); i++) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << endl;
    
    return 0;
}