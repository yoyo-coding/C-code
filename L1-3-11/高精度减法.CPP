#include<bits/stdc++.h>
using namespace std;
string a,b;
int am[10000];
int bm[10000];
int lena,lenb;
int c[10000];
int lenc;
int main(){
    cin>>a>>b;
    lena = a.size();
    lenb = b.size();
    if(lena < lenb || (lena == lenb && a < b)){
        cout<<"-"<<endl;
        swap(a,b);
        swap(lena,lenb);
    }
    for(int i = 0;i < lena;i++){
        am[lena-i] = a[i] - '0';
    }
    for(int i = 0;i < lenb;i++){
        bm[lenb-i] = b[i] - '0';
    }
    for(int i = 1;i <= lena;i++){
        if(am[i] < bm[i]){
            am[i] += 10;
            am[i+1]--;
        }
        c[i] = am[i] - bm[i];
    }
    lenc = lena;
    while(c[lenc] == 0 && lenc > 1){
        lenc--;
    }
    while(lenc){
        cout<<c[lenc--];
    }
    return 0;
}