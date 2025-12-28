#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int cat = 10;
    cin>>n;
    for(int i = 1; i <= n;i++){
        cat = cat+(cat/3);
    }
    cout<<cat;
    
    return 0;
}