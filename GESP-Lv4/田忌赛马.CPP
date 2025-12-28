#include<bits/stdc++.h>
using namespace std;
long long n;
int a[10000005],b[10000005];
int ans;
int main() {
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    for(int i = 0;i < n;i++){
        cin>>b[i];
    }
    sort(a+1,a+1+n);
	sort(b+1,b+1+n);
    for(int i=1,j=1;i<=n;i++){
		if(a[i]>=b[j]){
			j++;
            ans++;
		}
	}
    cout<<ans;
    return 0;
}