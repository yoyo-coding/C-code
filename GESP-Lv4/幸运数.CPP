#include<bits/stdc++.h>
using namespace std;
int n;
string num[10005];
int main() {
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>num[i];
    }
    for(int i = 0;i < n;i++){
        int size = num[i].size();
        if(num[i].size()%2 == 0){
            for(int j = 1;j < size;j+=2){
                int tmp = num[i][j]-'0';
                tmp *= 7;
                while(tmp>9){
                    tmp = tmp % 10 + tmp / 10;
                }
                num[i][j] = tmp + '0';
            }
        }
        else{
            for(int j = 0;j < size;j+=2){
                int tmp = num[i][j]-'0';
                tmp *= 7;
                while(tmp>9){
                    tmp = tmp % 10 + tmp / 10;
                }
                num[i][j] = tmp + '0';
            }
        }
        int sum = 0;
        for(int j = 0;j < size;j++){
            sum += num[i][j]-'0';
        }
        if(sum % 8 == 0){
            cout<<"T"<<endl;
        }else{
            cout<<"F"<<endl;
        }
    }
    return 0;
}