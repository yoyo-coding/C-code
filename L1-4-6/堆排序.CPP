#include<bits/stdc++.h>
using namespace std;
int main() {
    //声明堆
    //使用优先队列实现堆
    priority_queue<int> q;//大根堆
    //priority_queue<int, vector<int>, greater<int>> p; 小根堆
    int n,tmp;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin>>tmp;
        q.push(tmp); //将元素插入大根堆
    }
    for(int i = 0;i < n;i++){
        cout<<q.top() << " "; //输出堆顶元素
        q.pop(); //删除堆顶元素
    }
    
    return 0;
}