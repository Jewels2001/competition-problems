/*

*/

//build graph - locations are nodes
// 20 loc *
// go through,

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

int n, t;
vector<int> points;
vector<int> time;
vector<int> d;

vector<vector<int>> dist;
vector<vector<int>> dp;

int f(int s, int d) {

}

int main() {
  cin >> n >> t;
  points.resize(n);
  time.resize(n);
  d.resize(n);
  dp.resize(n, vector<int>(n-1));
  int totalPoints = 0;

  for(int i=0; i<n; i++) {
    cin >> points[i] >> time[i] >> d[i];
    //for sort-ing sake, d[-1] is the same as T+1 because you can
    //take as much time as needed
    if(d[i] == -1) {
      d[i] = T+1;
    }
  }
  for(int i=0; i<n+2; i++) {
    for(int j=0; j<n+2; j++) {
      cin >> dist[i][j];
    }
  }

  //initialize dp base case -
  dp[0][n] = 0;
  //cout:
  cout << " ";
  //cin:
  cin >> "";
  //debug cerr

  //round up
  (A+(B-1)) /B

  return 0;
}
