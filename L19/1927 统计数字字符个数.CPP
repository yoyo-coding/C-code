#include<bits/stdc++.h>
using namespace std;
int main(){
    //声明字符串
    char s[301];
    int cnt = 0;
    //读入带空格字符串
    cin.getline(s,300);
    //遍历字符串中每个字符，到‘\0’结束
    for(int i = 0;s[i] != '\0';i++){
        //判断是否为数字字符
        if(s[i] >= '0' && s[i] <= '9'){
            //如果是，计数自增
            cnt++;
        }
    }
    //输出计数
    cout<<cnt;
    return 0;
    
}