#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    for(int ii=1; ii<=t; ii++) {
        string i, p;
        bool ans = false;
        cin >> i >> p;
        int pos = 0;
        int num = 0;
        for(int j=0; j<p.length(); j++) {
            if(p[j] == i[pos]) {
                pos++;
            }
            else {
                num++;
            }
            if(pos >= i.length()) {
              ans = true;
              if(j < (p.length() - 1)) {
                num += (p.length() - i.length());
              }
              break;
            }
        }
        //
        cout << "Case #" << ii << ": ";
        if(ans) {
            cout << num << endl;
        }
        else {
            cout << "IMPOSSIBLE" << endl;
        }
    }

}
