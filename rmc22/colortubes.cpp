#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> a) {
    if(a[0] == a[1] == a[2]) {
        return true;
    }
    return false;
}


int main() {
    int n;
    cin >> n;

    vector<vector<int>> tubes(n+1);
    vector<stack<int>> tubes(n+1);

    for(int i=0; i<n+1; i++) {
        int b, m, t;
        cin >> b >> m >> t;
        tubes[i].push(b);
        tubes[i].push(m);
        tubes[i].push(t);
    }

    int moves = 0;

    // for all tubes

    // 1 - if tube is complete, continue on to next tube
    // 2 - if 2 are same, loop through to find next one
    // 2.1 move any others to empty tube
    // 2.2 move target to og tube (keep track of it)
    // 2.3 empty next tube? or just keep track of tube with space
    // (if tube.size == 3, continue)
    // 3 - check tube, if complete continue, etc
    
















}