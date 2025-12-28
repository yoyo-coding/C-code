#include<bits/stdc++.h>
using namespace std;
char s[505];
int x,y;

//定义字符串
//输入
//遍历
//  截取
//遍历
//  翻转
void rev(char s[]){
    int len = strlen(s);
    for(int i = 0;i < len/2;i++){
        swap(s[i],s[len-i-1]);
    }
}
int main(){
char w[505][505];
    cin.getline(s,505);
    int len = strlen(s);
    for(int i = 0;i <= len;i++){
        if(s[i] == ' '||s[i] == '\0'){
            w[x++][y] = '\0';
            y = 0;
        }
        else{
            w[x][y++] = s[i];
        }
    }
    for(int i = 0;i < x;i++){
        rev(w[i]);
        cout<<w[i]<<" ";
    }
    return 0;
    
}