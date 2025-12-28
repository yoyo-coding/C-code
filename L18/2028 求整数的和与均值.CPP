#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,tmp;
    int sum = 0;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++ ){
        scanf("%d",&tmp);
        sum += tmp;
    }
    printf("%d %.5lf",sum,sum/double(n));
    return 0;
    
}