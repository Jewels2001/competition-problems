#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }

int main() {
  int t;
  cin >> t;
  int cases = 1;
  while(t--) {
    int r, c, a,b;
    cin >> r >> c;
    a = (r*2) +1;
    b = (c*2) +1;

    vector<vector<char>> grid(a, vector<char>(b, '.'));
    for(int i=0; i<a; i++) {
        for(int j=0; j<b; j++) {
          if((i == 0 || i == 1) && (j == 0 || j == 1)) {
            // (0,0), (0,1), (1,0), (1,1)
            grid[i][j] = '.';
          } else if(i % 2 == 0) {
            // '+' or '-' row
            if(j % 2 == 0) {
              grid[i][j] = '+';
            } else {
              grid[i][j] = '-';
            }
          } else {
            // '|' or '.' row
            if(j % 2 == 0) {
              grid[i][j] = '|';
            } else {
              grid[i][j] = '.';
            }
          }
        }
    }
    cout << "Case #" << cases++ << ":" << endl;
    for(int i=0; i<a; i++) {
      for(int j=0; j<b; j++) {
        cout << grid[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
