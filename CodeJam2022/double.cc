#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000
#define MIL 1000000

int main() {
  int t;
  cin >> t;
  int cases = 1;
  while(t--) {
    string s;
    string ans = "";
    cin >> s;
    int same = 0;
    for(int i=0; i<s.length(); i++) {
      ans += s[i];
      if(s[i] < s[i+1]) {
        ans += s[i];
        // same = false;
      }
      else if(s[i] == s[i+1]) {
        ans += s[i];
        // if(same)
        same++;
      }
      // else {
      //   same = false;
      // }
      //cout << "S[i]: " << s[i] << " s[i+1]: " << s[i+1] << endl;
    }

cout << "same:" << same << "len" << s.length() << endl;

    cout << "Case #" << cases++ << ": ";
    if(same == s.length()) {
      cout << s << endl;
    } else {
      cout << ans << endl;
    }

  }
  return 0;
}
