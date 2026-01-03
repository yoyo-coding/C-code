#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,mod,x,y;
short book[10005][10005];
int rem(int x,int y){
	if(book[x][y] == -1) return -1;
	if(book[x][y]) return book[x][y];
	book[x][y]=-1;
	if(!x) return book[x][y]=1;
	if(!y) return book[x][y]=2;
	int num=(x+y)%mod;
	return book[x][y]=rem(num,(num%mod+y)%mod); 
}
int main() {
    cin>>t>>mod;
	for(int i=0;i<t;i++){
		cin>>x>>y;
		int ans=rem(x,y);
		if(ans == -1){
            cout<<"error"<<endl;
        }
		else if(ans == 1){
            cout<<"1"<<endl;
        }
		else{
            cout<<"2"<<endl;
        }
	}
    return 0;
}