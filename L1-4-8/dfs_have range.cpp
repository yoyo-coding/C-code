#include<bits/stdc++.h>
using namespace std;
int k = 1,n,r,a[21];
bool vis[21];
void dfs(int k){
	if(k == r+1){
		for(int i = 1;i <= r;i++){
			cout<<setw(3)<<a[i];
		}
		cout<<endl;
	}
	for(int i = a[k-1]+1;i <= n;i++){
		if(!vis[i]){
			a[k] = i;
			vis[i] = 1;
			dfs(k+1);
			vis[i] = 0;
		}
	}
	
}
int main(){
	cin>>n>>r;
	dfs(1);
	return 0;
}
