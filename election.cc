#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

int main() {
  int cases;
  cin >> cases;
  while(cases--) {
    int n, w, v1, v2;
    cin >> n >> v1 >> v2 >> w;
    int m = v1 + v2;

    int win = (v1/n) + 0.5*(n-m);
    double ans = win / n;
    if(ans > w) {
      cout << "GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!" << endl;
    }
    else if(ans <) {
      cout <<
    }
    //cout:
    cout << " ";
    //cin:
    cin >> "";
    //debug cerr

    //round up
    (A+(B-1)) /B
    cout << "Case #" << cases << ": " << ans << endl;
  }
  return 0;
}
