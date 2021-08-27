#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  double ans =0;
  double min =0;
  double max =0;

  for(int i=0; i<k; i++) {
    double r;
    cin >> r;
    ans += r;
  }
  double people = n-k;
  min = (ans + (people*-3.0)) / n;
  max = (ans + (people*3.0)) / n;

  cout << min << " " << max;

  return 0;
}
