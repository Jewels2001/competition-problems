#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> rungs(m);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a;
        rungs[i] = make_pair(a, a+1);
    }
    vector<int> finish(n);
    iota(begin(finish), end(finish), 1);
    for(int i=1; i<=n; i++) {
        int ans = i;
        for(int j=0; j<m; j++) {
            if(rungs[j].first == ans) {
                ans++;
            } else if(rungs[j].second == ans) {
                ans--;
            }
        }
        finish[ans-1] = i;
    }

    for(auto x : finish) {
        cout << x << endl;
    }
}