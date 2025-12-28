#include<bits/stdc++.h>
using namespace std;
int a[100],t[100];
void mergeSort(int l,int r){
    if(l>=r) return;
    int mid = (l+r)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    int ti = l,li = i,ri = mid+1;
    while(li <= mid && ri <= r){
        if(a[li] <= a[ri]){
            t[ti++] = a[li++];
        }else{
            t[ti++] = a[ri++];

        }
    }
    while(li <= mid){
        t[ti++] = a[li++];
    }
    while(ri <= r){
        t[ti++] = a[ri++];
    }
    for(int i = l;i <= r;i++){
        a[i] = t[i];
    }
}
int main(){
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i];
    }
    mergeSort(1,n);
    for(int i = 1 ; i <= n ; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}