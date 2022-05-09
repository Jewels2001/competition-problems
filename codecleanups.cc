//C
//not complete
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

int main() {
  int n;
  cin >> n;
  vector<int> days(n);
  int ans = 0;
  for(int i=0; i<n;i++) {
    cin >> days[i];
  }
  //cout << "ans: " << ans << " last: " << last << " temp: " << temp << endl;

  int last = -1;
  int dirty = 0;
  for(int i=0; i<n; i++) {
    int temp = days[i];
    //just cleaned or start
    if(last == -1) {
      last = i;
      dirty = 0;
    }
    else {
      for(int j=last; j<i;j++) {
        dirty += temp - days[j];
      }
    }

    if(dirty > 19) {
      ans++;
      last = i;
      dirty = 0;
    }
  }

  // else if(temp - last > 19) {
  //     ans++;
  //     last = temp;
  //   }
  // else {
  //   ans++;
  //   last = 0;
  // }
  if(last != -1) {
    ans++;
  }
  cout << ans;
  return 0;
}
