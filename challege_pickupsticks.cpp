#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> above(n+1);
    vector<int> stick(n+1, 0);
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        stick[b]++;
        above[a].push_back(b);
    }
    
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(stick[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()) {
        // push a stick
        int top = q.front();
        q.pop();
        ans.push_back(top);
        
        // add next higher sticks to order
        for(auto i : above[top]) {
            stick[i]--;
            if(stick[i] == 0) {
                q.push(i);
            }
        }
    }
    
    if(ans.size() == n) {
        for(auto i : ans) {
            cout << i << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    
}