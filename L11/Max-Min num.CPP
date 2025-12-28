#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,temp,Max = -1,Min = 201;
    cin>>n;
    for(int i = 1; i <= n;i++){
        cin>>temp;
        if(temp > Max){
            Max = temp;
        }
        if(temp < Min){
            Min = temp;
        }
    }
    cout<<Max-Min;
    
    return 0;
    
}