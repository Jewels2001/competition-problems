#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000


int main() {
  int n;
  while(cin >> n, n != -1) {
    vector<vector<int>> abc (n, vector<int>(n));
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        cin >> abc[i][j];
      }
    }
    // go through ajacency matrix
    for(int i=0; i<n; i++) {
      bool is_triangle = false;
      for(int j=0; j<n; j++) {
        if(i == j) {
          continue;
        }
        // if(abc[i][j] == 1 && first == -1) {
        //   first = j;
        // } else {
        //   second = j;
        // }
        for(int k=0; k<n; k++) {
          if(j == k || k == i) {
            continue;
          }
          if(abc[i][j] && abc[i][k] && abc[j][k]) {
            is_triangle = true;
          }
        }
      }
      if(!is_triangle) {
        cout << i << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
