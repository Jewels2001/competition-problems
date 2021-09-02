#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for(int i=0; i<n;i++) {
    int b;
    double p;
    cin >> b >> p;
    double min = 0;
    double bpm = 0;
    double max = 0;

    bpm = (60*b)/p;
    min = (60*(b-1)/p);
    max = (60*(b+1)/p);

    cout << fixed << setprecision(4) << min << " " << bpm << " " << max << endl;
  }
  return 0;
}
