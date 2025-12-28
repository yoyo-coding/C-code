#include <bits/stdc++.h>  
using namespace std; 

const int N = 1005;

void setLen(int a[], int i);
void strToNumArr(string s, int a[]);
void showNumArr(int a[]);
string numArrToStr(int a[]);
string div(string A, int b, int& r);

int main(){
	
	string A;
	int b;
	cin >> A >> b;

	int r = 0; // ำเสý
	
	cout << div(A, b, r) << endl;
	cout << r << endl;
	
	return 0;
}
void setLen(int a[], int i){
	while(a[i] == 0 && i > 1)
		i--;
	a[0] = i;
}

void strToNumArr(string s, int a[]){
	a[0] = s.size();
	for(int i = 1; i <= a[0]; i++)
		a[i] = s[a[0] - i] - '0';
}

void showNumArr(int a[]){
	for(int i = a[0]; i >= 1; i--)
		cout << a[i];
	cout << endl;
}

string numArrToStr(int a[]){
	string res = "";
	for(int i = 1; i <= a[0]; i++)
		res += char(a[i] + '0');
	reverse(res.begin(), res.end());
	return res;
}

string div(string A, int b, int& r){
	int a[N] = {}, c[N] = {};
	strToNumArr(A, a);

	for(int i = a[0]; i >= 1; i--){
		c[i] = (r * 10 + a[i]) / b;
		r = (r * 10 + a[i]) % b;
	}

	setLen(c, a[0]);

	return numArrToStr(c);
}


