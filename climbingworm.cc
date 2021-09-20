#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,h;
  cin >> a >> b >> h;

  int ans = 0;
  int temp = 0;

  while(temp <= h) {
    temp += a;
    ans++;
    if(temp >= h)
      break;
    temp -= b;
  }

  cout << ans;

  return 0;
}
