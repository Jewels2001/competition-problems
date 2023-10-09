#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    int cases = 1;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> elves(n);
        vector<ll> group1(2);
        vector<ll> group2(2);
        for(int i=0; i<n; i++) {
            ll x;
            cin >> x;
            elves[i] = x;
        }
        sort(begin(elves), end(elves));
        group1[0] = (elves[0]);
        group2[1] = (elves[n-1]);
        if(n == 5) {
            int distA = abs(elves[2] - elves[0]);
            int distB = abs(elves[n-1] - elves[2]);
            if(distA <= distB) {
                group1[1] = (elves[2]);
                group2[0] = (elves[n-2]);
            } else {
                group1[1] = (elves[1]);
                group2[0] = (elves[2]);
            }
        } else {
            group1[1] = (elves[1]);
            group2[0] = (elves[n-2]);
        }
        double ans =  ((group2[0] + group2[1]) / 2.0) - ((group1[0] + group1[1]) / 2.0);

        cout << "Case #" << cases++ << ": " << setprecision(10) << fixed << ans << endl; //case++
    }
}