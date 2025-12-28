#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,s;
    cin>>a>>b>>c;
    if(a%4 == 0 and a%100 != 0 or a%400 == 0){
        d = 29;
    }
    else{
        d = 28;
    }
    switch(b){
        case 2:s = 31;break;
        case 3:s = 31+d;break;
        case 4:s = 2*31+d;break;
        case 5:s = 2*31+d+30;break;
        case 6:s = 3*31+d+30;break;
        case 7:s = 3*31+d+30+30;break;
        case 8:s = 4*31+d+30+30;break;
        case 9:s = 5*31+d+30+30;break;
        case 10:s = 5*31+d+90;break;
        case 11:s = 6*31+d+90;break;
        case 12:s = 6*31+d+120;break;
    }
    s += c;
    cout<<s;
    return 0;
    
}