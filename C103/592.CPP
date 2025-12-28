#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e13;
ll n;
struct Point{
    ll x,y;
}point[200005];
ll d[200005];
bool ok[200005];
//计算距离平方
ll cost(int i,int j){
    ll dx = (ll)point[i].x - (ll)point[j].x;
    ll dy = (ll)point[i].y - (ll)point[j].y;
    return dx*dx + dy*dy;
}

ll prim(){
    ll ans = 0;
    fill(d,d+n,INF);
    memset(ok,0,sizeof(ok));
    d[0] = 0;
    for(int k = 0; k < n; k++){
        int i = -1;
        //找到未访问节点中距离最小的点
        for(int j = 0; j < n; j++){
            if(!ok[j] && (i == -1 || d[j] < d[i])){
                i = j;   
            }
        }
        
        ok[i] = true;
        ans = max(ans, d[i]);
        
        //其他节点的距离
        for(int j = 0; j < n; j++){
            if(!ok[j]){
                d[j] = min(d[j], cost(i, j));
            }
        }
    }
    return ans;
}

int main() {
    freopen("sea.in","r",stdin);
    freopen("sea.out","w",stdout);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> point[i].x;
    }
    for(int i = 0; i < n; i++){
        cin >> point[i].y;
    }
    
    ll result = prim();
    ll day = ceil(sqrt((double)result));
    cout<<day<<endl;
    return 0;
}