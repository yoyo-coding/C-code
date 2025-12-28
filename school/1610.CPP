#include<bits/stdc++.h>
using namespace std;

int main(){
    const int raySpeed = 299792458;
    int n;
    long long m;
    cin>>n;
    m = n * 365.25 * 86400 * raySpeed;
    cout<<m<<endl;
    return 0;
    
}