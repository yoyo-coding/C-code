#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[8,2,6,7,1,5,3,9];
    sort(a,a+8);
    int x;
    cin>>x;
    int l = 0,r = 7;
    while(l < r){
        int mid = (l+r)/2; //取中点
        if(a[mid] > x){
            r = mid - 1;
        }
        else if(a[mid] < x ){
            l = mid + 1;
        }
        else{
            cout<<"找到了";
            break;
        }
    }
    return 0;
    
}