#include<bits/stdc++.h>
using namespace std;
int main() {
    string n;
    cin>>n;
    int len = n.size();
    int k;
    cin>>k;
    while(k--){  
        for(int i = 0;i < len - 1;i++){
            if(n[i] > n[i + 1]){
                for(int j = i;j < len - 1;j++){
                    n[j] = n[j+1];
                }
                break;
            }
        }
        len--;
    }
    int tmp = 0;
    while(n[tmp] == '0' && tmp != (len-1)){
        tmp++;
    }
    for(int i = tmp;i < len;i++){
        cout<<n[i];
    }
    
    return 0;
}