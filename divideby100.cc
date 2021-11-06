#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;

int main() {
  ll n, m;
  cin >> n >> m;
  long double a = (double)n/m;
  cout << "n: " << n << "m: " << m << "n/m: " << n/m << "a: " << a << endl;
  cout << fixed << a << endl; // doesn't work, just tests
  //need to parse string to remove 0s.

  return 0;
}
