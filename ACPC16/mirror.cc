//with cases
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

int main() {
  int t;
  cin >> t;
  int cases = 1;
  while(t--) {
    int r, c;
    cin >> r >> c;
    vector<string> g(r);
    for(int i=0; i<r; i++) {
        cin >> g[i];
    }

    reverse(begin(g), end(g));
    for(auto &s : g) {
        reverse(begin(s), end(s));
    }

    cout << "Test " << cases++ << endl; //case++
    for(int i=0; i<r; i++) {
        cout << g[i] << endl;
    }
  }
  return 0;
}