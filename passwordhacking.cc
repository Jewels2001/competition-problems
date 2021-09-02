#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  priority_queue<double> p;

  for(int i=0; i<n;i++) {
    string t;
    double temp;
    cin >> t >> temp;
    p.push(temp);
  }

  double ans = 0;
  for(int j=1; j<n+1;j++) {
    ans += (j*p.top());
    p.pop();
  }

  cout << fixed << ans;

  return 0;
}
