#include<bits/stdc++.h>
using namespace std;

int main() {
    // freopen("xjj.in","r",stdin);
    // freopen("xjj.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    
    // 鍗曡皟闃熷垪锛屽瓨鍌ㄤ笅鏍囷紝瀵瑰簲鍊煎崟璋冮€掑
    deque<int> q;
    vector<int> result;
    
    for(int i = 0; i < n; i++) {
        // 绉婚櫎瓒呭嚭绐楀彛鑼冨洿鐨勫厓绱�
        while(!q.empty() && q.front() <= i-k) {
            q.pop_front();
        }
        
        // 缁存姢鍗曡皟鎬э紝绉婚櫎姣斿綋鍓嶅厓绱犲ぇ鐨勫厓绱�
        while(!q.empty() && a[q.back()] >= a[i]) {
            q.pop_back();
        }
        
        q.push_back(i);
        
        // 褰撶獥鍙ｅぇ灏忚揪鍒発鏃讹紝寮€濮嬭褰曟渶灏忓€�
        if(i >= k-1) {
            result.push_back(a[q.front()]);
        }
    }
    
    // 杈撳嚭缁撴灉
    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i != result.size()-1) cout << " ";
    }
    cout << endl;
    
    return 0;
}