#include<bits/stdc++.h>
using namespace std;
#define ll long long
int extend(queue<string>& q,unordered_map<string,int>& ma,unordered_map<string,int>& mb){
    int d = ma[q.front()];
    while(!q.empty()&&ma[q.front()] == d){
        
    }
}
int bfs(){
    if(A == B){
        return 0;
    }
    queue<string> qa,qb;
    unordered_map<string,int> ma,mb;
    qa.push(A),qb.push(B);
    ma[A] = 0,mb[B] = 0;
    int step;
    while(!qa.empty() && !qb.empty()){
        if(qa.size() <= qb.size()){
            step = 
        }
    }
}
int main(){
    
    return 0;
}