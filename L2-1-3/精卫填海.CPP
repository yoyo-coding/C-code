#include<iostream>
using namespace std;
int v,n,c,tj[10002],tl[10002]; 
int dp[10002]; 
int main()
{
	cin>>v>>n>>c;
	for(int i=1;i<=n;i++) cin>>tj[i]>>tl[i]; 
	for(int i=1;i<=n;i++)
		for(int j=c;j>=tl[i];j--)
			dp[j]=max(dp[j],dp[j-tl[i]]+tj[i]);
	if(dp[c]<v) cout<<"Impossible"; 
	else{ 
		int i=c;
		while(dp[i]>=v) i--; 
		cout<<c-(i+1); 
	}
	return 0;
}

