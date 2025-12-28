#include<bits/stdc++.h>
using namespace std;
long long n;
string a="0123456789ABCDEF";
void print(int i){
	cout<<a[i / 16]<<a[i % 16]<<" ";
}
int main(){
	cin>>n;
	if(n == 0){
        cout<<"00";
        return 0;
    }
	while(n > 0){
		int k = n % 128;
		n /= 128;
		if(n > 0)
            print(k+128);
		else 
            print(k);
	}
	return 0;
}
