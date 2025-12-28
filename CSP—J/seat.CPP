#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m,n;
int sc[1005];
int ma[1005][1005];
bool cmp(int a,int b){
    return a > b;
}
int main() {
    cin>>n>>m;
    int p = n*m;
    for(int i = 0 ;i < p;i++){
        cin>>sc[i];
    }
    int c = sc[0];
    sort(sc,sc+p,cmp);
    cout<<"step1"<<endl;
    for(int i = 0;i < p;i++){
    	cout<<sc[i]<<" ";
	}
	cout<<endl;
    int cnt = 0;
    for(int i = 0;i < m;i++){
        if(cnt == p) break;
        if(i % 2 == 0){
            for(int j = n;j >= 1;j--){
                if(cnt == p) break;
                ma[i][j] = sc[cnt];
                cnt++;
            }
        }
        else{
            for(int j = 1;j <= n;j++){
                if(cnt == p) break;
                ma[i][j] = sc[cnt];
                cnt++;
            }
        }
    }
    cout<<"step2"<<endl;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
      		cout<<ma[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"step3"<<endl;
    return 0;
}