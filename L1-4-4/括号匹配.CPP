#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<char> s;
    string c;
    cin>>c;
    int len = c.size();
    for(int i = 0;i < len;i++){
        if(c[i] == '('){
            s.push('(');
        }
        else if(c[i] == ')'){
            if(s.empty()){
                cout<<"No"<<endl;
                return 0;
            }
            else{
                s.pop();
            }
        }
    }
    if(s.empty()){
        cout<<"Yes"<<endl;
    }
    
    return 0;
}