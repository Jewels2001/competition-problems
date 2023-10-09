#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        bool exist = false;
        for(int i=0; i< n; i++) {
            int temp;
            cin >> temp;
            if(temp == k) {
                exist = true;
            }
        }
        if(exist) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}