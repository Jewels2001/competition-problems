/*
By: Julie Wojtiw-Quo
Binary search on the distance, greedily placing the access points and then
comparing the number of access points to the one provided by input. The greedy
function is what determines the direction of the binary search.
*/

#include <bits/stdc++.h>
using namespace std;

int h[100010];
int n, m;
bool check(const double& dist) {
  double ap = h[0] + dist;
  int num = 1;
  for(int i=0; i<m; i++) {
    if(abs(ap-h[i]) <= dist) {
      continue;
    }
    else {
      num++;
      if(num > n) {
        return false;
      }
      ap = h[i] + dist;
    }
  }
  return true;
}

int main() {
  int cases;
  cin >> cases;
  while(cases--) {
    cin >> n >> m;

    for(int i=0; i<m; i++) {
      cin >> h[i];
    }
    sort(h, h+m);

    double l = 0;
    double r = h[m-1];
    double dist = 0;

    while(r-l > 0.01) {
      dist = (r+l)/2;

      if(check(dist)) {
        r = dist;
      }
      else {
        l = dist;
      }
    }

    cout << fixed << setprecision(1) << dist << endl;
  }
  return 0;
}
