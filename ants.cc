#include <bits/stdc++.h>
using namespace std;

int main() {
  int cases;
  cin >> cases;
  while(cases--) {
    int l, n;
    cin >> l >> n;
    int earliest = 0;
    int latest = 0;

    for(int j=0; j<n; j++) {
      int ant = 0;
      cin >> ant;

      int left = ant;
      int right = l-ant;
      earliest = max( min(left, right), earliest);
      latest = max(max(left, right), latest);
    }
    cout << earliest << " " << latest << endl;
  }
  return 0;
}
