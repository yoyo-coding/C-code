#include<bits/stdc++.h>
using namespace std;
int a[25][25];int toInt(char c){
	if(c >= 'A' && c <= 'Z')
		return c-'A'+10;
	return c-'0';
}
//将数值打印成十六进制数的操作 
void printHx(int x){
	char c;
	if(x > 9)
		c = x + 65 - 10;
	else
		c = x + '0';
	cout<<c;
} 

struct Node{
	int hd; //灰度
	int sl; //数量 
}c[300]; 

bool cmp(Node a,Node b){
	if(a.sl == b.sl)
		return a.hd < b.hd;
	return a.sl > b.sl;
}

int main(){
	int n;
	cin>>n;
	string s;
	for(int i = 1;i <= n;i++){
		cin>>s;
		int t;  //保存拆解出来的灰度值
		for(int j = 0;j < s.size();j+=2){
			t = toInt(s[j])*16 + toInt(s[j+1]);
			a[i][j/2+1] = t;
			c[t].sl++;
		} 
	}
	//初始化
	for(int i = 0;i <= 255;i++)
		c[i].hd = i;
	sort(c,c+256,cmp);
	//打印
	for(int i = 0;i < 16;i++){
		printHx(c[i].hd/16);
		printHx(c[i].hd%16);
	} 
	cout<<endl;
	int len = s.size()/2;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= len;j++){
			int minn = 256;
			int p = 0;//编号
			//枚举
			for(int k = 0;k < 16;k++){
				if(abs(c[k].hd - a[i][j])  < minn){
					minn = abs(c[k].hd - a[i][j]);
					p = k; 
				}
			} 
			printHx(p);
		}
		cout<<endl;
	}
	return 0;
}



