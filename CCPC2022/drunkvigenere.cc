#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

void change(char a, int b) {
  while(!isupper(a)) {
    if(a < 41) {
      int temp = 'A' - a;
      a = 'Z' - temp;
    }
  }
}

int main() {
  string c, k;
  cin >> c >> k;

  string ans = "";
  for(int i=0; i<c.length();i++) {
    int a = k[i] - 'A';
    if(i % 2) {
      ans += c[i]+a;
    }
    else {
      ans += c[i]-a;
      if(!isupper(ans[i])) {

      }
    }
  }
  cout << ans << endl;
  //cout:
  cout << " ";
  //cin:
  cin >> "";
  //debug cerr

  //round up
  (A+(B-1)) /B

  return 0;
}
