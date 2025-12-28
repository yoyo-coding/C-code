#include<bits/stdc++.h>
using namespace std;
void graph(int a,int b,char f){
    for(int i = 0 ;i < a;i++){
        for(int j = 0 ;j < b;j++){
            cout<<f;
        }
        cout<<endl;
    }
}
int main(){
    int a,b;
    char f;
    cin>>a>>b>>f;
    graph(a,b,f);
    return 0;
    
}