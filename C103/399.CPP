#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Event {
    int time;
    int change;
};

bool cmp(Event a, Event b) {
    if (a.time == b.time) {
        return a.change < b.change;
    }
    return a.time < b.time;
}

int tm2min(string t) {
    int h = (t[0] - '0') * 10 + (t[1] - '0');
    int m = (t[3] - '0') * 10 + (t[4] - '0');
    return h * 60 + m;
}

int main() {
    int n;
    cin >> n;
    
    vector<Event> ev;
    
    for (int i = 0; i < n; i++) {
        string tr;
        int r;
        cin >> tr >> r;
        
        string st = tr.substr(0, 5);
        string et = tr.substr(6, 5);
        
        int sm = tm2min(st);
        int em = tm2min(et);
        
        Event start_event = {sm, r};
        Event end_event = {em, -r};
        ev.push_back(start_event);
        ev.push_back(end_event);
    }
    
    sort(ev.begin(), ev.end(), cmp);
    
    int cur = 0;
    int mx = 0;
    
    for (auto e : ev) {
        cur += e.change;
        mx = max(mx, cur);
    }
    
    cout << mx << endl;
    
    return 0;
}