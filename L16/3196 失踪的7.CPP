#include<bits/stdc++.h>
using namespace std;
int seven(int x){
    int a,b = x;
    for(int i = 1;i <= x;i++){
        a = i;
        while(a){
            if(a%10 == 7){
                b--;
                break;
            }
            a/=10;
        }
    }
    return b;
}
int main(){
    int n;
    cin>>n;
    cout<<seven(n)
    return 0;
    
}