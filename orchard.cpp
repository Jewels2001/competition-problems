#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

double dp[5][5][5][5][9];

double f(int r, int g, int b, int y, int s) {
  // base cases:
  if(r == 0 && g == 0 && b == 0 && y == 0) {
    return 1.00;
  }
  if(s == 0) {
    return 0.00;
  }
  // dp
  if(dp[r][g][b][y][s] != -1.0) {
    return dp[r][g][b][y][s];
  }
  // recursion:
  double ans = 0.00;
  int bins = 6;
  // empty tree(s)
  if(r == 0) {
    bins--;
  }
  if(g == 0) {
    bins--;
  }
  if(b == 0) {
    bins--;
  }
  if(y == 0) {
    bins--;
  }

  // raven:
  ans += (1.00/bins)*f(r,g,b,y,s-1);
  // fruits:
  if(r != 0)
    ans += (1.00/bins)*f(r-1,g,b,y,s);
  if(g != 0)
    ans += (1.00/bins)*f(r,g-1,b,y,s);
  if(b != 0)
    ans += (1.00/bins)*f(r,g,b-1,y,s);
  if(y != 0)
    ans += (1.00/bins)*f(r,g,b,y-1,s);
  // basket:
  if(y >= b && y >= g && y >= r) {
    ans += (1.00/bins)*f(r,g,b,y-1,s);
  }
  else if(b >= y && b >= g && b >= r) {
    ans += (1.00/bins)*f(r,g,b-1,y,s);
  }
  else if(g >= y && g >= b && g >= r) {
    ans += (1.00/bins)*f(r,g-1,b,y,s);
  }
  else if(r >= y && r >= b && r >= g) {
    ans += (1.00/bins)*f(r-1,g,b,y,s);
  }

  // six dice rolls
  return dp[r][g][b][y][s] = ans;

}

int main() {
  int r, g, b, y, s;
  cin >> r >> g >> b >> y >> s;
  fill(&dp[0][0][0][0][0], &dp[0][0][0][0][0]+sizeof(dp)/sizeof(dp[0][0][0][0][0]), -1.0);
  cout << fixed << setprecision(10) <<f(r, g, b, y, s) << endl;

  // round up
  // (A+(B-1)) /B

  return 0;
}
