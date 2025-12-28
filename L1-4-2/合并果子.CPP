#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main() {
    int n,cnt = 0;
    int s = 0;
    int tmp;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    sort(a+s, a + n);
    while(s < n-1){
        cnt+=a[s];
        cnt+=a[s+1];
        //cout << a[s]<<" "<<a[s+1]<<endl;
        a[s+1] += a[s];
        s++;
        
        tmp = s;
        while(a[tmp]>a[tmp+1] && tmp < n-1){
            swap(a[tmp],a[tmp+1]);
            tmp++;
        }
    }
    cout<<cnt;
    return 0;
}