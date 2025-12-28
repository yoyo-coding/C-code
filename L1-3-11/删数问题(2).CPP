#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    int n,i,j,k;
    cin>>a>>n;
    int len = a.size();
    for(int k = 0;k < n;k++){
        for(int i = 0;i < len;i++){
            if(a[i] > a[i+1]){
                for(int j = i;j < len - 1;j++){
                    a[j] = a[j+1];
                }
                break;
            }
        }
        len--;
    }
    i = 0;
    while(i <= len - 1 && a[i] == '0'){
        i++;
    }
    if(i == len){
        cout<<0<<endl;
    }
    else{
        for(int j = i;j <= len-1;j++){
            cout<<a[j];
        }
    } 
    return 0;
}