#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n;
int problems[MAXN];
bool canCompleteDays(long long k) {
    if (n < k) return false;
    for (long long day = 1; day <= k; day++) {
        if ((long long)problems[day - 1] < day) {
            return false;
        }
    }
    
    return true;
}

int main() {
    // 鎻愰珮杈撳叆杈撳嚭鏁堢巼
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> problems[i];
    }
    
    // 棰勫厛鎺掑簭锛岄伩鍏嶆瘡娆heck閮介噸鏂版帓搴�
    sort(problems, problems + n, greater<int>());
    
    // 浜屽垎绛旀鎵炬渶澶уぉ鏁�
    long long left = 0, right = min((long long)n, 100000LL);
    long long maxDays = 0;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (canCompleteDays(mid)) {
            maxDays = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << maxDays << "\n";
    return 0;
}