#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;
const double PI = acos(-1.0);

int main() {
  double a, n;
  cin >> a >> n;

  //A = P^2 / (4*PI)     A*4*PI = P^2  sqrt(A*4*PI) = P
  double r = sqrt(a*4 / PI);
  double circ = PI * r;

  if(n >= circ) {
    cout << "Diablo is happy!" << endl;
  }
  else {
    cout << "Need more materials!" << endl;
  }
  return 0;
}
