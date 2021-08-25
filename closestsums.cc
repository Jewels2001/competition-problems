#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int count = 1;
  while (cin >> n) {
    cout << "Case " << count << ":" << endl;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
      cin >> a[i];
      //int temp; a.push_back(temp);
    }
    int m;
    cin >> m;

    for(int i=0; i<m; i++) {
      int closest = INT_MAX;
      int target;
      cin >> target;

      //pairwise sums
      for (int j=0; j< a.size(); j++) {
        for(int k = j-1; k<a.size(); k++) {
          //find a[i] + a[j] closest to target
          int sum = a[j] + a[k];
          if( abs(target - sum) < abs(target - closest)) {
            closest = sum;
          }
        }
      }
      cout << "Closest sum to " << target << " is " << closest << "." << endl;
    }
    count++;
  }
  return 0;
}
