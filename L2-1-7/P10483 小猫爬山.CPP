#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, w;
int weight[20];
int cars[20];
int min_cars = INT_MAX;

void dfs(int cat_idx, int used_cars) {

    if (used_cars >= min_cars) {
        return;
    }
    if (cat_idx == n) {
        min_cars = min(min_cars, used_cars);
        return;
    }
    for (int i = 0; i < used_cars; i++) {
        if (cars[i] + weight[cat_idx] <= w) {
            cars[i] += weight[cat_idx];
            dfs(cat_idx + 1, used_cars);
            cars[i] -= weight[cat_idx];
        }
    }
    if (used_cars + 1 < min_cars) { // 鍓灊锛氬鏋滄柊杞︽暟閲忓凡缁忓ぇ浜庣瓑浜庡綋鍓嶆渶浼樿В锛屽垯涓嶈€冭�?
        cars[used_cars] = weight[cat_idx];
        dfs(cat_idx + 1, used_cars + 1);
        cars[used_cars] = 0; // 鍥炴�?
    }
}

int main() {
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    
    // 鎸夐噸閲忛檷搴忔帓搴忥紝浼樺厛瀹夋帓閲嶇殑灏忕尗锛岃繖鏍峰彲浠ユ洿鏃╁湴鍙戠幇鏇翠紭瑙ｏ紝鎻愰珮鍓灊鏁堢�?
    sort(weight, weight + n, greater<int>());
    
    dfs(0, 0);
    
    cout << min_cars << endl;
    
    return 0;
}