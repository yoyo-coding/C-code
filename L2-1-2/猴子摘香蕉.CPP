#include<bits/stdc++.h>
using namespace std;
struct block{
    int x,y,z;
}blocks[1000005],blocks2[1000005],blocks3[1000005];
int n;
int main() {
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>blocks[i].x>>blocks[i].y>>blocks[i].z;
    }
    for(int i = 0;i < n;i++){
        blocks2[i].x = blocks[i].y;blocks2[i].y = blocks[i].z;blocks2[i].z = blocks[i].x;
        blocks3[i].x = blocks[i].z;blocks3[i].y = blocks[i].x;blocks3[i].z = blocks[i].y;
    }
    
    return 0;
}