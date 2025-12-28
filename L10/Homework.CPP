#include<bits/stdc++.h>
using namespace std;
int main(){
    int s;
    cin >> s;

    int product = 1;
    int count = 0;

    for (int i = 1; i <= 30; ++i) {
        product *= i;
        ++count;
        if (product >= s) {
            break;
        }
    }

    cout<<count<<endl;

    //--------------
    int n;
    cin >> n;

    int gold = 0, silver = 0, bronze = 0;

    for (int i = 0; i < n; ++i) {
        int g, s, b;
        cin >> g >> s >> b;
        gold += g;
        silver += s;
        bronze += b;
    }

    int total = gold + silver + bronze;

    cout << gold << " " << silver << " " << bronze << " " << total << endl;
    
    return 0;
    
}