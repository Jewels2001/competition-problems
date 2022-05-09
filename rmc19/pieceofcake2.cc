/*
By: Julie Wojtiw-Quo
Basic implementation finding the max volume of the 4 cases:
//(n-v)*(n-h)
//v*h
//(n-v)*h
//v*(n-h)
then multiplying the max of those by the last, given, dimension: 4.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, h, v;
  cin >> n >> h >> v;

  cout << 4 * max(max(((n-v)*(n-h)), (v*h)), max(((n-v)*h), v*(n-h)));
  return 0;
}
