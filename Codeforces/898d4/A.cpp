#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string x;
        cin >> x;
        if(x == "bca" || x == "cab") {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}