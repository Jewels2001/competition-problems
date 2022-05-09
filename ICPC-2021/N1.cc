#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000


int main() {
  int n, w;
  cin >> n >> w;
  vector<string> g(n), f(n);
  string ans = "-----";

  for(int i=0; i<n; i++) {
    cin >> g[i] >> f[i];
    for(int j=0; j<5; j++) {
      if(f[i][j] == G) {
        ans[j] = g[i][j];
      }
    }
  }
  //vector<string> valid(w);
  for(int i=0; i<w; i++) {
    string v;
    cin >> v;
    for(int j=0; j<5; j++) {

    }
  }

  //cout:
  cout << " ";
  //cin:
  cin >> "";
  //debug cerr

  //round up
  (A+(B-1)) /B

  return 0;
}
