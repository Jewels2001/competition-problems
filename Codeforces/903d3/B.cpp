#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int m = min(a, b);
        m = min(m, c);
        
        if((a % m) || (b % m) || (c % m)) {
            cout << "NO" << endl;
            continue;
        }
        int count = 0;
        count += ((a / m) - 1) + ((b / m) - 1) + ((c / m) - 1);
        if(count <= 3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
}