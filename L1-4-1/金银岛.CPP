#include<bits/stdc++.h>
using namespace std;

struct metal{
    int all_price;
    int all_weight;
    double price; 
}m[10000];
bool cmp(metal a,metal b){
    return a.price>b.price;
}

int bag;
double bag_price;
int metal_num;
int k;
int main() {
    cin>>k;
    for(int cnt = 0 ; cnt < k ; cnt ++){
        bag = 0; bag_price = 0;metal_num = 0;
        cin>>bag;
        cin>>metal_num;
        for(int i = 0 ; i < metal_num ; i++){
            cin>>m[i].all_weight>>m[i].all_price;
            m[i].price = double(m[i].all_price) / m[i].all_weight;
        }
        sort(m,m+metal_num,cmp);
        for(int i = 0;i < metal_num;i++){
            if(bag > m[i].all_weight){
                bag -= m[i].all_weight;
                bag_price += m[i].all_price;
            }else if(bag <= m[i].all_weight){
                bag_price += bag * m[i].price;
                break;
            }
        }
        cout<<fixed<<setprecision(2)<<bag_price<<endl;
    }
    
    return 0;
}