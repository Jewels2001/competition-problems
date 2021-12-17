#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;
const double PI = acos(-1.0);

int main() {
  int n;
  cin >> n;

  double length = 0.00;
  for(int i=0;i<n;i++) {
    double a,b,c;
    cin >> a >> b >> c;
    if(c >= a && c >= b) {
      length += c;
    }
  }
  cout << length << endl;

  //round up
  (A+(B-1)) /B

  return 0;
}
