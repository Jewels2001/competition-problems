#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000


int main() {
  int n;
  cin >> n;

  int mult = -1;
  bool newNum = true;
  for(int i=0; i<n; i++) {
    int num;
    cin >> num;
    if(newNum) {
      mult = num;
      newNum = false;
    }
    else if(num % mult == 0) {
      cout << num << endl;
      newNum = true;
    }
  }

  return 0;
}
