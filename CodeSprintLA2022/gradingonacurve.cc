#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

int main() {
  double n, t;
  cin >> n >> t;
  vector<double> s(n);
  int k = t;
  for(int i=0; i<n; i++) {
    cin >> s[i];
  }
  sort(s.rbegin(), s.rend());
  int quarter = ceil(n*0.25) -1;
  int half = ceil(n*0.5) - 1;
  int three = ceil(n*0.75) - 1;
  // cout << quarter << " " << half << " " << three << endl;

  //try grade curve weights
  bool b = false;
  for(int i=t; i>0; i--) {
    k = i;
    // cout << "HI ";
    // cout << s[three] << " " << i << " " << s[three]/i << endl;
    if(s[three]/i < 0.70) {
      continue;
    }
    // cout << "WOO ";
    // cout << s[half] << " " << i << " " << s[half]/i << endl;

    if(s[half]/i < 0.80) {
      continue;
    }
    // cout << "YAY ";
    // cout << s[quarter] << " " << i << " " << s[quarter]/i << endl;

    if(s[quarter]/i < 0.90) {
      continue;
    }
    b = true;
    break;

    // cout << quarter << " " << half << " " << three << endl;
    // cout << "N:" << n << endl;
    // if(quarter/n >= 0.25 && half/n >= 0.50 && three/n >= 0.75) {
    //   b = true;
    //   break;
    // }
  }
  if(!b) {
    cout << -1 << endl;
  }
  else {
    cout << k << endl;
  }

  return 0;
}
