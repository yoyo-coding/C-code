#include<bits/stdc++.h>
using namespace std;
void get_length(int a){
    int i = 0;
    while(a){
        a = a/10;
        i++;
    }
    cout<<i;
}
int main(){
    int a;
    cin>>a;
    get_length(a);
    return 0;
    
}