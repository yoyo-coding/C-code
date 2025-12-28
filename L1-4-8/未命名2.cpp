#include<bits/stdc++.h>
using namespace std;
int vis1[100],vis2[100],vis3[100];//列,左上右下，左下右上
int cnt = 0;
void dfs(int i){
	if(i == 9){
		cnt++;
		return;
	}
	for(int j = 1;j <= 8;j++){
		if(!(vis1[j] || vis2[i-j+8] || vis3[i+j])){
			vis1[j] = 1;
			vis2[i-j+8] = 1;
			vis3[i+j] = 1;
			dfs(i+1);
			vis1[j] = 0;
			vis2[i-j+8] = 0;
			vis3[i+j] = 0;
		}
	}
}
int main(){
	dfs(1);
	cout<<cnt;
	return 0;
}
