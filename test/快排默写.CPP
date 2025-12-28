#include<bits/stdc++.h>
using namespace std;
int a[1000];
void quickSort(int l,int r){
    if(l >= r) return;
    int i = l,j = r,mid = a[(l+r)/2];
    while(i <= j){
        while(a[i] < mid) i++;
        while(a[j] > mid) j--;
        if(i <= j){
            swap(a[i],a[j]);
            i++;
            j--;
        }

    }
    quickSort(l,j);
    quickSort(i,r);
}
int main(){
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i];
    }
    quickSort(1,n);
    for(int i = 1 ; i <= n ; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}