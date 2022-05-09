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
    vector<int> c(3), m(3), y(3), k(3);
    for(int i=0; i<3; i++) {
      cin >> c[i] >> m[i] >> y[i] >> k[i];
    }
    sort(begin(c), end(c));
    sort(begin(m), end(m));
    sort(begin(y), end(y));
    sort(begin(k), end(k));

    int ansC = c[0];
    int ansM = 0;
    int ansY = 0;
    int ansK = 0;
    int total = ansC;

    if(total + m[0] > MIL) {
      ansM = MIL - total;
    } else {
      ansM += m[0];
    }
    total += ansM;

    if(total + y[0] > MIL) {
      ansY = MIL - total;
    } else {
      ansY += y[0];
    }
    total += ansY;

    if(total + k[0] > MIL) {
      ansK = MIL - total;
    } else {
      ansK += k[0];
    }
    total += ansK;

    cout << "Case #" << cases++ << ": ";
    if(total < MIL) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << ansC << " " << ansM << " " << ansY << " " << ansK << endl;
    }
  }
  return 0;
}
