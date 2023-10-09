#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> days(n);
    for(int i=0; i<n; i++) {
        // mess, clean amount
        cin >> days[i].first >> days[i].second;
    }
    vector<int> parents(d);
    for(int i=0; i<d; i++) {
        cin >> parents[i];
    }

    int ans = 0;
    bool impossible = false;


    
    int p1 = 0;
    int p2 = 0;
    for(int i=0; i<parents.size(); i++) {
        // first by clean, then by day.
        priority_queue<pair<int, int>> clean;
        int mess = 0;
        p2 = parents[i]-1;
        if(i > 0) {
            p1 = parents[i-1];
        }
        // cout << "P1:" << p1 << endl;
        // cout << "P2:" << p2 << endl;
        // add mess:
        for(int i=p2; i>=p1; i--;) {
            mess += days[i].first;
        }
        // if mess created on last day is greater than clean
        if(days[p2].first > days[p2].second) {
            cout << -1 << endl;
            return 0;
        } else if(days[p2].first > 0)

        for(int i=p2; i>=p1; i--;) {
            // if(days[i].first > days[i].second) {
            //     impossible = true;
            //     cout << -1 << endl;
            //     return 0;
            // }
            // if current mess exists
            if(days[i].first > 0) {
                mess -= days[i].second;
            }


        }



    }

    




}