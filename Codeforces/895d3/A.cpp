/*
vessel possibilities:
both are equal
one has more, one has less
one has more, one has none
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        double a, b, c;
        cin >> a >> b >> c;
        // case 1: both are equal already
        if(a == b) {
            cout << 0 << endl;
            continue;
        }
        double diff = max(a, b) - min(a, b);
        double eq = (a + b) / 2; // 3 + 2 / 2 = 2.5 or 8 + 2 / 2 = 5
        double amtOff = max(a, eq) - min(a, eq);
        // case 2: one has more than other, but within c difference
        if((diff/2) <= c) {
            cout << 1 << endl;
        } else {
            // case 3: one has more than other, more than c difference
            //cout << "A:" << a << " B: " << b << " C: " << c << endl;
            //cout << "eq: " << eq << " diff " << diff << " amt " << amtOff << endl;
            cout << ceil(amtOff / c) << endl;
            //cout << (eq - amtOff) / c << endl;
        }
    }   
}