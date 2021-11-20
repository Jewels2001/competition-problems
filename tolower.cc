#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;
const double PI = acos(-1.0);

int main() {
  int p, t;
  cin >> p >> t;
  int ans = 0;
  for(int i=0; i<p;i++) {
    int testCase = 0;
    for(int j=0; j<t; j++) {
      string temp;
      cin >> temp;
      bool allLower = true;
      for(int k=1; k<temp.length(); k++) {
        if(isupper(temp[k])) {
          allLower = false;
          break;
        }
      }
      if(allLower) {
        testCase++;
      }
    }
    if(testCase == t){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
