#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

int main() {
  int t;
  cin >> t;
  int cases = 1;
  while(t--) {
    double n;
    cin >> n;
    vector<double> grades(n);
    double currentAvg = 0.0;
    for(int i=0; i<n; i++) {
      cin >> grades[i];
      currentAvg += grades[i];
    }
    currentAvg /= n;
    double above = 0;
    for(int i=0; i<n; i++) {
      if(grades[i] > currentAvg) {
        above++;
      }
    }
    cout << setprecision(3) << fixed << (above/n)*100 << "%" << endl;
  }
  return 0;
}
