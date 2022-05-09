#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000


int main() {
  double a;
  cin >> a;
  double ans1 = (1/a)*100;
  double b = 100 - a;
  double ans2 = (1/b)*100;

  cout << fixed << setprecision(10) << ans1 << endl << ans2 << endl;


  return 0;
}
