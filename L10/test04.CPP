#include <iostream>
using namespace std;

int main(){
    int n, p, q, pr = 0, qr = 0, s;
    
    // 读取n, p, q的值
    cin >> n >> p >> q;
    
    // 循环n次，每次读取一个整数s
    for (int i = 0; i < n; i++) {
        cin >> s;
        
        // 如果s小于p，则增加pr计数器
        if (s < p) {
            pr += 1;
        }
        // 如果s大于q，则增加qr计数器
        if (s > q) {
            qr += 1;
        }
    }
    
    // 输出结果
    cout << pr << endl;
    cout << qr << endl;

    return 0;
}