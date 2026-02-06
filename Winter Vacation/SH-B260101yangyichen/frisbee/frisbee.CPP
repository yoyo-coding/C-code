#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 300005;
int n;
int h[MAXN];
int l[MAXN], r[MAXN]; // 鍗曡皟鏍堟暟缁�
ll ans = 0;

// 鎵惧埌姣忎釜浣嶇疆宸﹁竟绗竴涓皬浜庡畠鐨勪綅缃�
void find_bound() {
    stack<int> st;
    // 鎵惧乏杈圭晫
    for(int i = 1; i <= n; i++) {
        while(!st.empty() && h[st.top()] >= h[i]) {
            st.pop();
        }
        if(st.empty()) l[i] = 0;
        else l[i] = st.top();
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    
    // 鎵惧彸杈圭晫
    for(int i = n; i >= 1; i--) {
        while(!st.empty() && h[st.top()] >= h[i]) {
            st.pop();
        }
        if(st.empty()) r[i] = n + 1;
        else r[i] = st.top();
        st.push(i);
    }
}

int main() {
    freopen("frisbee.in", "r", stdin);
    freopen("frisbee.out", "w", stdout);
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }
    
    find_bound();
    
    // 瀵逛簬姣忎竴瀵�(i,j)锛宨<j锛屽鏋渕in(h[i],h[j])澶т簬瀹冧滑涔嬮棿鎵€鏈夊厓绱狅紝鍒欐湁鏁�
    // 鎴戜滑鏋氫妇姣忎釜浣嶇疆浣滀负鍖洪棿涓殑鏈€灏忓€�
    
    for(int i = 1; i <= n; i++) {
        int left_bound = l[i] + 1;   // 宸﹁竟鐣�
        int right_bound = r[i] - 1;  // 鍙宠竟鐣�
        
        // 鍦ㄥ尯闂碵left_bound, right_bound]涓紝h[i]鏄渶灏忓€�
        // 鎵€浠ヤ换浣曞寘鍚綅缃甶鐨勫瓙鍖洪棿閮芥弧瓒�"涓棿鍏冪礌閮藉皬浜庣鐐规渶灏忓€�"鐨勬潯浠�
        
        // 璁＄畻浣嶇疆i瀵圭瓟妗堢殑璐＄尞锛屼娇鐢ㄦ暟瀛﹀叕寮忛伩鍏嶅惊鐜�
        
        ll left_count = i - left_bound;      // 宸︿晶浣嶇疆鏁�
        ll right_count = right_bound - i;    // 鍙充晶浣嶇疆鏁�
        
        // i涓庡乏渚т綅缃厤瀵圭殑璐＄尞锛歴um_{j=left_bound}^{i-1} (i-j+1)
        // = sum_{k=2}^{left_count+1} k = (left_count+1)(left_count+2)/2 - 1
        ans += (left_count * (left_count + 3)) / 2;
        
        // i涓庡彸渚т綅缃厤瀵圭殑璐＄尞锛歴um_{j=i+1}^{right_bound} (j-i+1)
        // = sum_{k=2}^{right_count+1} k = (right_count+1)(right_count+2)/2 - 1
        ans += (right_count * (right_count + 3)) / 2;
        
        // 宸︿晶浣嶇疆閫氳繃i涓庡彸渚т綅缃厤瀵圭殑璐＄尞
        // = sum_{left=left_bound}^{i-1} sum_{right=i+1}^{right_bound} (right-left+1)
        // = right_count * sum_{left=left_bound}^{i-1} (i-left+1) + 
        //   left_count * sum_{right=i+1}^{right_bound} (right-i) + 
        //   left_count * right_count
        // = right_count * [left_count*(left_count+3)/2] +
        //   left_count * [right_count*(right_count+1)/2] +
        //   left_count * right_count
        ans += right_count * (left_count * (left_count + 3)) / 2;
        ans += left_count * (right_count * (right_count + 1)) / 2;
        ans += left_count * right_count;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}