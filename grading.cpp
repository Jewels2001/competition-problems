#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  int now = 0;
  cin >> now;
  if(now >= a) {
	cout << "A";
  } else if(now >= b) {
	cout << "B";
  } else if(now >= c) {
  	cout << "C";
  } else if(now >= d) {
  	cout << "D";
  } else if(now >= e) {
  	cout << "E";
  } else {
  	cout << "F";
  }
  cout << endl;
  return 0;
}
