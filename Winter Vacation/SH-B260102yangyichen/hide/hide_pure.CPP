#include<iostream>
using namespace std;

const int MAXN = 1005;
int n;
int l[MAXN], g[MAXN];
int nl, ng;

int main(){
    freopen("hide.in","r",stdin);
    freopen("hide.out","w",stdout);
    
    cin>>n;
    nl = 0;
    ng = 0;
    
    for(int i = 0; i < n; i++){
        char c;
        int v;
        cin>>c>>v;
        if(c == 'L'){
            l[nl] = v;
            nl++;
        }else{
            g[ng] = v;
            ng++;
        }
    }
    
    // 鍐掓场鎺掑簭L鏁扮粍
    for(int i = 0; i < nl-1; i++){
        for(int j = 0; j < nl-1-i; j++){
            if(l[j] > l[j+1]){
                int temp = l[j];
                l[j] = l[j+1];
                l[j+1] = temp;
            }
        }
    }
    
    // 鍐掓场鎺掑簭G鏁扮粍
    for(int i = 0; i < ng-1; i++){
        for(int j = 0; j < ng-1-i; j++){
            if(g[j] > g[j+1]){
                int temp = g[j];
                g[j] = g[j+1];
                g[j+1] = temp;
            }
        }
    }
    
    int ans = n;
    
    // 鏋氫妇鎵€鏈夊彲鑳界殑淇濈暀鏂规
    for(int keep_l = 0; keep_l <= nl; keep_l++){
        for(int keep_g = 0; keep_g <= ng; keep_g++){
            int valid = 1;
            
            // 妫€鏌ョ害鏉熸槸鍚﹀啿绐�
            if(keep_l > 0 && keep_g > 0){
                int max_l = l[keep_l-1];
                int min_g = g[ng-keep_g];
                if(max_l < min_g){
                    valid = 0;
                }
            }
            
            // 濡傛灉绾︽潫鏈夋晥锛屾洿鏂扮瓟妗�
            if(valid){
                int remove_count = (nl - keep_l) + (ng - keep_g);
                if(remove_count < ans){
                    ans = remove_count;
                }
            }
        }
    }
    
    cout<<ans<<endl;
    return 0;
}