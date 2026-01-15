#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int k;
    int cnt = 0;
    cin>>t>>k;
    while(t--){
        int N;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        string s;
        cin>>N;
        cin>>s;

        for(char c : s){
            if(c == 'C') cnt1++;
            else if(c == 'O') cnt2++;
            else cnt3++;
        }

        if(cnt1 % 2 != 0 || cnt2 % 2 != 0 || cnt3 % 2 != 0){
            cout<<-1<<endl;
            continue;
        }

        vector<int> res(s.size(), 0);
        vector<int> p_c, p_o, p_w;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'C') p_c.push_back(i);
            else if(s[i] == 'O') p_o.push_back(i);
            else p_w.push_back(i);
        }

        if(k == 0){
            for(int i = 0; i < p_c.size(); i += 2){
                if(i+1 < p_c.size()){
                    res[p_c[i]] = 1;
                    res[p_c[i+1]] = 1;
                }
            }

            for(int i = 0; i < p_o.size(); i += 2){
                if(i+1 < p_o.size()){
                    if(res[p_o[i]] == 0){
                        res[p_o[i]] = 2;
                        res[p_o[i+1]] = 2;
                    } else {
                        res[p_o[i+1]] = res[p_o[i]];
                    }
                }
            }

            for(int i = 0; i < p_w.size(); i += 2){
                if(i+1 < p_w.size()){
                    if(res[p_w[i]] == 0){
                        res[p_w[i]] = 3;
                        res[p_w[i+1]] = 3;
                    } else {
                        res[p_w[i+1]] = res[p_w[i]];
                    }
                }
            }
            
            set<int> unique_ops;

            for(int x : res){
                if(x > 0) unique_ops.insert(x);
            }

            cnt = unique_ops.size();
        } else {
            for(int i = 0; i < p_c.size(); i += 2){
                if(i+1 < p_c.size()){
                    res[p_c[i]] = 1;
                    res[p_c[i+1]] = 1;
                }
            }
            
            for(int i = 0; i < p_o.size(); i += 2){
                if(i+1 < p_o.size()){
                    res[p_o[i]] = 1;
                    res[p_o[i+1]] = 1;
                }
            }
            
            for(int i = 0; i < p_w.size(); i += 2){
                if(i+1 < p_w.size()){
                    res[p_w[i]] = 1;
                    res[p_w[i+1]] = 1;
                }
            }
            
            cnt = 1;
        }
        int max = 0;
        for(int val : res){
            if(val > max) max = val;
        }
        
        cout<<max<<endl;

        for(int i = 0; i < s.size(); i++){
            cout<<res[i];
            if(i < s.size()-1) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}