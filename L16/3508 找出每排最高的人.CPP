#include <bits/stdc++.h>
using namespace std;
void func(){
    int max = 0;
    int a;
    for(int i = 0;i < 10;i++){
        cin>>a;
        if(a > max){
            max = a;
        }
    }
    cout<<max<<endl;

}
int main(){
    int n;
    cin>>n;
    for(int i = 0;i < n;i++){
        func();
    }

}