#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    while(t--) {
        int n;
        int k = 0;
        int cur = 0;
        cin >> n;
        // either pq to always sort, or vector and sort once?
        // only need to remember lowest time, can go as far as that i's s/2 + 1
        priority_queue<pair<int, int>> pq; // sort by lowest time, then room num
        for(int i=0; i<n; i++) {
            pair<int, int> temp;
            cin >> temp.second >> -temp.first;
            pq.push(temp);
        }

    }

}