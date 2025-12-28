#include<bits/stdc++.h>
using namespace std;
int main(){
    double a;
    cin>>a;
    if(a<=400){
        cout<<"Novo salario:"<<a+a*0.15<<endl;
        cout<<"Reamuste ganho:"<<a*0.15<<endl;
        cout<<"Em percentual:"<<"15%";
    }
    else if(a<=800){
        cout<<"Novo salario:"<<a+a*0.12<<endl;
        cout<<"Reamuste ganho:"<<a*0.12<<endl;
        cout<<"Em percentual:"<<"12%";
    }
    else if(a<=1200){
        cout<<"Novo salario:"<<a+a*0.1<<endl;
        cout<<"Reamuste ganho:"<<a*0.1<<endl;
        cout<<"Em percentual:"<<"10%";
    }
    else if(a<=2000){
        cout<<"Novo salario:"<<a+a*0.07<<endl;
        cout<<"Reamuste ganho:"<<a*0.07<<endl;
        cout<<"Em percentual:"<<"7%";
    }
    else{
        cout<<"Novo salario:"<<a+a*0.04<<endl;
        cout<<"Reamuste ganho:"<<a*0.04<<endl;
        cout<<"Em percentual:"<<"4%";
    }
    return 0;
    
}