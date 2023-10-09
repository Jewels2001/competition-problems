#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 1;
        vector<int> product(n);
        for(int i=0; i<n; i++) {
            cin >> product[i];
        }
        sort(begin(product), end(product));
        bool done = false;
        for(auto x : product) {
            if(done) {
                ans *= x;
                continue;
            }
            else {
                ans *= x+1;
                done = true;
                continue;
            }

        }
        cout << ans << endl;
    }
}