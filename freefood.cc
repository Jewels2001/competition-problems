#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool free[366] = {false};
  for(int i=0; i<n;i++) {
    int s, t;
    cin >> s >> t;
    fill(free+s, free+t+1,true);
  }
  cout << count(free, free+366, true) << endl;
  return 0;
}
