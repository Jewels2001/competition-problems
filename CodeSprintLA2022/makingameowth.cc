//with cases
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

int main() {
  int n, p, x, y;
  int ans = 0;
  cin >> n >> p >> x >> y;
  int count = 1;
  int i=0;
  while(i < p) {
    if(count % n == 0) {
      ans +=y;
    } else {
      ans += x;
      i++;
    }
    count++;
  }

  if(count % n == 0) {
    ans += y;
  }
  cout << ans << endl;
  return 0;
}
