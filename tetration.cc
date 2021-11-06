#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;

const double e = 2.718281;
const double e2 = 0.36788;

int main() {
  double n;
  cin >> n;

  double a = pow(n, 1.0/n);
  cout << fixed << setprecision(6) << a << endl;
  return 0;
}
