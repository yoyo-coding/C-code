#include<bits/stdc++.h>
using namespace std;
int n;
int a[1005], b[1005];
int x, y;

int main(){
    freopen("hide.in","r",stdin);
    freopen("hide.out","w",stdout);
    
    cin>>n;
    x = y = 0;
    for(int i = 0; i < n; i++){
        char c;
        int v;
        cin>>c>>v;
        if(c == 'L') a[x++] = v;
        else b[y++] = v;
    }
    
    for(int i = 0; i < x-1; i++){
        for(int j = 0; j < x-1-i; j++){
            if(a[j] > a[j+1]){
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    
    for(int i = 0; i < y-1; i++){
        for(int j = 0; j < y-1-i; j++){
            if(b[j] > b[j+1]){
                int t = b[j];
                b[j] = b[j+1];
                b[j+1] = t;
            }
        }
    }
    
    int r = n;
    
    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++){
            int f = 1;
            if(i > 0 && j > 0){
                int p = a[i-1];      // 淇濈暀鐨凩绾︽潫涓殑鏈€澶у€�
                int q = b[y-j];      // 淇濈暀鐨凣绾︽潫涓殑鏈€灏忓€�
                if(p < q) f = 0;     // 濡傛灉L鐨勬渶澶у€� < G鐨勬渶灏忓€硷紝鍒欐棤瑙�
            }
            
            if(f){
                int s = (x - i) + (y - j);
                if(s < r) r = s;
            }
        }
    }
    
    cout<<r;
    return 0;
}