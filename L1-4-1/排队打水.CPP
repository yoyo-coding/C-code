#include<bits/stdc++.h>
using namespace std;
int t[1000],s[1000];
int main() {
    int n,r;
    cin>>n>>r;
    for(int i = 1;i <= n;i++){
        cin>>t[i];
    }
    sort(t+1,t+n+1);
    int j = 1,time = 0;
    for(int i = 1;i <= n;i++){
        if(j > r) j = 1;
        s[j] += t[i];
        time += s[j];
        j++;
    }
    cout<<time;
    return 0;
}
