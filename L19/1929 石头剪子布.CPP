#include<bits/stdc++.h>
using namespace std;
//R Ê¯Í·
//s ¼ôµ¶
//p ²½
int main(){
    char s1[10],s2[10];
    int n;
    cin>>n;
    for(int i = 1;i <= n; i++){
        cin>>s1>>s2;
        if(strcmp(s1,s2) == 0){
            cout<<"Tie";
        }
        else if(s1[0] == 'R' && s2[0] == 'S'){
            cout<<"Player1";
        }
        else if(s1[0] == 'S' && s2[0] == 'R'){
            cout<<"Player2";
        }
        else if(s1[0] == 'R' && s2[0] == 'P'){
            cout<<"Player2";
        }
        else if(s1[0] == 'P' && s2[0] == 'R'){
            cout<<"Player1";
        }
        else if(s1[0] == 'P' && s2[0] == 'S'){
            cout<<"Player2";
        }
        else if(s1[0] == 'S' && s2[0] == 'P'){
            cout<<"Player1";
        }
        cout<<endl;
    }
    return 0;
    
}