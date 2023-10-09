#include <bits/stdc++.h>
using namespace std;



int main() {
    int r, g, b, k;
    cin >> r >> g >> b >> k;
    if(b == g) {
        cout << "YES" << endl;
        int i = g;
        cout << i << endl;
        while(i--) {
            cout << "B G" << endl;
        }
    } else {
        int a1 = max(g, b);
        int a2 = min(g, b);
        int t = (a1 - a2) % (k+3);
        int t1 = (a1 - a2) / (k+3);
        int x = a1 - t1;
        if(t == 0 && (t1 + x) <= 100000 && r >= t1) {
            cout << "YES" << endl;
            cout << (t1 + x) << endl;
            while(t1--) {
                if(a1 == g) {
                    cout << "R G" << endl;
                } else {
                    cout << "R B" << endl;
                }
            }
            while(x--) {
                cout << "B G" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
}