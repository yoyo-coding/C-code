#include<bits/stdc++.h>
using namespace std;
int p[100][100],ans = 0x3f3f3f3f,n,m;
int d[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
void dfs(int k,int x,int y){
	if(x == n && y == m){
		ans = min(ans,k);
	}
	for(int i = 0;i < 4;i++){
		int fx = x+d[i][0];
		int fy = y+d[i][1];
		if(1 <= fx && fx <= n && 1 <= fy && fy <= m && p[fx][fy] == 0){
			p[fx][fy] = 1;
			dfs(k+1,fx,fy);
			p[fx][fy] = 0;
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin>>p[i][j];
		}
	}
	dfs(0,1,1);
	cout<<ans;
	return 0;
}
