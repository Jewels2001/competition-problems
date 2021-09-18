#include <bits/stdc++.h>
using namespace std;

int main() {
  int cases;
  cin >> cases;
  for(int i=0; i<cases;i++) {
    double n;
    cin >> n;
    int ans = 0;
    if(n == 0) {
      cout << ans;
    }
    else {
    ans = ceil(n/400);
    cout << ans;
    }
    cout << endl;
  }
  return 0;
}
