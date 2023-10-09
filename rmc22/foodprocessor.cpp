#include <bits/stdc++.h>
using namespace std;


int main() {
    int s, t, n;
    cin >> s >> t >> n;
    priority_queue<pair<int, int>> pq;

    for(int i=0; i<n; i++) {
        int m, h;
        cin >> m >> h;
        //double rate = (h * (log(s/t))) / (log(2));
        pq.push(make_pair(m,h));
    }
    // code still passes without pq.empty()....
    if(pq.empty() || pq.top().first < s) {
        cout << -1 << endl;
        return 0;
    }


    double ans = 0;
    pair<int, int> cur_blade = pq.top();
    int best = cur_blade.second;
    while(!pq.empty() && s != t) {
        cur_blade = pq.top();
        best = min(best, cur_blade.second);
        pq.pop();
        // while there is a better blade (ie, still s size but strictly lower h)
        // don't care about strictly lower h anymore, saving the best one.
        // && pq.top().second < cur_blade.second
        while(!pq.empty() && pq.top().first >= s) {
            cur_blade = pq.top();
            best = min(best, cur_blade.second);
            pq.pop();
        }
        double s1 = t;
        if(!pq.empty()) {
            s1 = max(t, pq.top().first);
        }
        ans += (best * (log(s/s1))) / (log(2.0));
        s = s1;

        // cout << "X:" << ans << endl;
        // cout << "BLADE: " <<  cur_blade.first << " " << cur_blade.second << endl;
        // cout << "S: " << s << endl;
    }
    cout << scientific << ans << endl;
}