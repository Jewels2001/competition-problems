#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

int main() {
  int t;
  cin >> t;
  int cases = 1;
  while(t--) {
    int n;
    cin >> n;
    priority_queue<int> g;
    for(int i=0; i<n; i++) {
      int temp;
      cin >> temp;
      g.push(-temp);

    }
    // sort(begin(g), end(g));
    // for(int i=0; i<n; i++) {
    //   cout << g[i] << " ";
    // }
    int ans =0;
    int counter = 1;
    while(!g.empty()) {
      if(abs(g.top()) >= counter) {
        ans++;
        counter++;
      }
      g.pop();
    }

    cout << "Case #" << cases++ << ": " << ans << endl; //case++
  }
  return 0;
}
