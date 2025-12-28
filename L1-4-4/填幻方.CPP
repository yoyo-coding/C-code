#include<bits/stdc++.h>
using namespace std;
int n;
int a[25][25];
int main(){
	cin>>n;
	int x=0,y=n/2;
	a[x][y]=1;
	for(int cnt=2;cnt<=n*n;cnt++){
		int tx=(x+n-1)%n;
		int ty=(y+1)%n;
		if(a[tx][ty]==0){
			a[tx][ty]=cnt;
		}else{
			tx=(x+1)%n;
			ty=y;
			a[tx][y]=cnt;
		}
		x=tx;
		y=ty;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

