#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,max = 0,min = 205, maxnum = 0,minnum = 0;
    cin>>n;
    int a[105];
    //输入数组
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    //求最大值
    for(int b = 1;b <= n;b++){
        if(a[b] > max){
            max = a[b];
            maxnum = b;
        }
    }
    //求最小值
    for(int c = 1;c <= n;c++){
        if(a[c] < min){
            min = a[c];
            minnum = c;
        }
    }
    //求中间数
    if(maxnum > minnum){
        int tmp = maxnum;
        maxnum = minnum;
        minnum = tmp;
    }
    for(int z = maxnum+1;z < minnum;z++){
        cout<<z<<" "<<a[z]<<endl;
    }
    return 0;
    
}