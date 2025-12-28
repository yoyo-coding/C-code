#include<bits/stdc++.h>
using namespace std;
int a[5] = {1,3,5,7,9},b[5] = {2,4,6,8,10},r[10];
int len = 0,len_a = 5,len_b = 5;
int main(){
    int i = 0,j = 0;
    while(i < len_a && j < len_b){
        if(a[i] <= b[j]){
            r[len++] = a[i++];
        }
        else{
            r[len++] = b[j++];
        }
    }
    while(i < len_a){
        r[len++] = a[i++];
    }
    while(j < len_b){
        r[len++] = b[j++];
    }
    for(int i = 0;i < 10;i++){
        cout << r[i] << " ";
    }
    return 0;
}