#include<bits/stdc++.h>
using namespace std;
string a1,b1;
int a[1000],b[1000],c[1000],x;
int main(){
    cin>>a1>>b1;
    int lena = a1.size();
    int lenb = b1.size();
    for(int i = 0;i < lena;i++){
        a[lena-i] = a1[i] - '0';
    } 
    for(int i = 0;i < lenb;i++){
        b[lenb-i] = b1[i] - '0';
    }
    for(int i = 1;i <= lenb;i++){
        x = 0;
        for(int j = 1;j <= lena;j++){
            c[i+j-1] = a[j] * b[i] + x + c[i+j-1];
            x = c[i+j-1]/10;
            c[i+j-1] %= 10;
        }
        c[lena+i] = x;
    }
    int lenc = lena + lenb;
    while(c[lenc] == 0 && lenc > 1){
        lenc--;
    }
    for(int i = lenc;i > 0;i--){
        cout<<c[i];
    }
    return 0;
}