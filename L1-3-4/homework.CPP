#include<bits/stdc++.h>
using namespace std;

struct Node{
    int num;
    int cnt;
};

Node node[1005];

bool cmp(Node a,Node b){
    return a.num < b.num;
}

int main() {
    int n,num;
    cin>>n;

    bool tmp;
    int len = 0;

    for(int i = 1;i <= n;i++){
        cin>>num;
        tmp = 0;

        //遍历
        //如果存在
        for(int j = 1;j <= len;j++){
            if(node[j].num == num){
                node[j].cnt++;
                tmp = 1;
                break;
            }
        }

        //不存在
        if(!tmp){
            node[++len].num = num;
            node[len].cnt = 1;
        }
    }
    sort(node+1,node+1+len,cmp);
    for(int i = 1;i <= len;i++){
        cout<<node[i].num<<" "<<node[i].cnt<<endl;
    }
    return 0;
}