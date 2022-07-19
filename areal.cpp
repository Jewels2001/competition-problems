#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

// A = l*w
// P = 2l + 2w
// since square, A = l*l and P = 2l + 2l = 4l

int main() {
  long double area = 0;
  cin >> area;
  cout << fixed << setprecision(10) << (sqrt(area))*4.0;

  return 0;
}
