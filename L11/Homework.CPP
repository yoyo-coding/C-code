
#include<bits/stdc++.h>
using namespace std;
int main(){
    /*int n;
    char c;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>c;
        cout<<char(c-32);
    }
    //--------------
    int n,num,tmp,a = 0;
    cin>>n>>num;
    for(int i = 0;i < n;i++){
        cin>>tmp;
        if(num == tmp){
            a++;
        }
    }
    cout<<a;

    //--------------

    int n,m,b = 0;
    cin>>n>>m;
    for(int i = n;i <= m;i++){
        if(i%17 == 0){
            b+=i;
        }
    }
    cout<<b;*/

    //--------------

    int n,cnt = 0,tmp;
    cin>>n;
    int a,b,c,d;
    for(int i = 0;i <= n;i++){
        cin>>tmp;
        a = tmp%10;
        b = tmp/10%10;
        c = tmp/100%10;
        d = tmp/1000;
        if(a-b-c-d > 0){
            cnt++;
        }
    }
    cout<<cnt;

    return 0;
    
}