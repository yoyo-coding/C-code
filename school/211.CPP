#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[8];
    int max = -0x3f3f3f3f;
    for(int i = 0; i < 8; i++){
        cin >> a[i];
    }
    for(int i = 0; i < 8; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    cout<<max;
    
    return 0;
}