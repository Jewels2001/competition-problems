#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

vector<int> candles_R(50, 0);
vector<int> candles_T(50, 0);


int main() {
  // precompute ages?
  // factorial but addition is nth triangle numbers
  int current = 0;
  for(int i=1; i<45; i++) {
    current += i;
    candles_R[i] = current-6;
    candles_T[i] = current-3;
  }

  int d, r, t;
  cin >> d >> r >> t;
  int total = r+t;

  for(int i=d; i<candles_R.size(); i++) {
    if(candles_R[i] + candles_T[i-d] == total) {
      cout << r - candles_R[i] << endl;
    }
  }

  return 0;
}
