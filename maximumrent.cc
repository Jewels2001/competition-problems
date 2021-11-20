#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;
const double PI = acos(-1.0);



int main() {
  int a,b,m,o;
  cin >> a >> b >> m >> o;
  int r = 0;

  for(int x=1;x<m;x++) {
    int y = m-x;
    if((2*x+y)>= o) {
      r = max(r, (a*x)+(b*y));
    }
  }
  cout << r << endl;
  return 0;
}
