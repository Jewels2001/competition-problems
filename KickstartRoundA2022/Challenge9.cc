#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int caseNo = 1;
    while(t--) {
        string n;
        cin >> n;

        int a = 0;
        for(int i=0; i<n.length(); i++) {
            a += n[i] - '0';
        }
        int b = 9 - (a % 9);
        if(b == 9) {
          b = 0;
        }
        char c = b + '0';
        string ans = "hi";
        for(int j=0; j<=n.length(); j++) {
          if(!j && !b) continue;
          if((n[j] - '0') > b) {
            ans = n.substr(0, j) + c + n.substr(j);
            break;
          }
          else if(j+1 >= n.length()) {
            ans = n + c;
          }
        }

        cout << "Case #" << caseNo++ << ": " << ans << endl;
    }
}
