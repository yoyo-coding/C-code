#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e13;
ll n, v;
struct Point{
    ll x,y;
}point[200005];
ll d[200005];
bool ok[200005];
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
    d[n] = 0; //虚拟点
    for(int k = 0; k < n; k++){
        int i = -1;
        //找未访问节点中距离最小的
        for(int j = 0; j < n; j++){
            if(!ok[j] && (i == -1 || d[j] < d[i])){
                i = j;   
            }
        }
        
        ok[i] = true;
        ans += d[i];        
        //更新其他节点
        for(int j = 0; j < n; j++){
            if(!ok[j]){
                d[j] = min(d[j], min(v, cost(i, j))); //考虑空降
            }
        }
    }
    return ans;
}

int main() {
    // freopen("inform.in","r",stdin);
    // freopen("inform.out","w",stdout);
    cin >> n >> v;
    for(int i = 0; i < n; i++){
        cin >> point[i].x >> point[i].y;
    }
    
    ll result = prim();
    cout<<result<<endl;
    return 0;
}