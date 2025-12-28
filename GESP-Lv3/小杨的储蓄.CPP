#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,d;
    cin>>n>>d;
    int jar[1005] = {};
    int tmp;
    for(int i = 1 ; i <= d ; i++){
        cin>>tmp;
        jar[tmp] += i;
    }
    for(int i = 0 ; i < n ; i++){
        cout<<jar[i]<<" ";
    }
    
    return 0;
}