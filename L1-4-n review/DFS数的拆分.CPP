#include<bits/stdc++.h>
using namespace std;
int n,a[1005] = {1};
void dfs(int k,int r){
	if(r == 0){
		if(k == 2) return;
		cout<<n<<"=";
	 	for(int i = 1;i < k-1;i++){
			cout<<a[i]<<"+";
		}
		cout<<a[k-1]<<endl;
		return;
	}
	for(int i = a[k-1];i <= r;i++){
		a[k] = i;
		dfs(k+1,r-i);
	}
}
int main(){
	cin>>n;
	dfs(1,n);
	return 0;
}
