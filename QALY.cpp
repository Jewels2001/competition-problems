#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int n;
  cin >> n;
  double ans;
  double temp;
  double a, b;
  for(int i=0; i<n; i++) {
    cin >> a >> b;
    temp = a*b;
    ans += temp;
  }
  cout << fixed << setprecision(3) << ans;
  return 0;
}
