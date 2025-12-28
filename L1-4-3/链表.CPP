#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node * next;
};
//Í·²å
void cain_head_insert(node * head,int n){
    for(int i = 0;i < n;i++){
        node * p = new node;
        cin >> p->data;
        p->next = head->next;
        head->next = p;
    }
}
//Î²²å
void cain_final_insert(node * head,int n){
    node * r = head;
    for(int i = 0;i < n;i++){
        node * p = new node;
        cin >> p->data;
        r->next = p;
        r = r->next;
    }
    
}
int main() {
    cin>>n;
    node * head = new node;
    head->next = NULL;
    cain_head_insert(head, n);
    
    
    return 0;
}