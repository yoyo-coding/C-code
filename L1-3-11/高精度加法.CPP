#include<bits/stdc++.h>
using namespace std;
string a,b;
int am[100000],bm[100000];
int lena,lenb,lenans;
int ans[100000];
int main(){
    cin>>a>>b;
    lena = a.size();
    lenb = b.size();
    for(int i = 0;i < lena ;i++){
        am[lena - i] = a[i]-'0';
    }
    for(int i = 0;i < lenb ;i++){
        bm[lenb - i] = b[i]-'0';
    }
    lenans = 1;
    int x = 0;
    while(lenans <= lena || lenans <= lenb){
        ans[lenans] = am[lenans] + bm[lenans] + x;
        x = ans[lenans]/10;
        ans[lenans] %= 10;
        lenans++;
    }
    ans[lenans] = x;
    if(!(ans[lenans])){
        lenans--;
    }
    for(int i = lenans;i > 0;i--){
        cout<<ans[i];
    }
    return 0;
}