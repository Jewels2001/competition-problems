/*
By: Julie Wojtiw-Quo
A DP problem using bottom-up method. We can use iteration and compute the base
cases first. This avoids recursion and saves the number of ways to make smaller
amounts so that those can be added in when computing larger amounts.
*/

#include <bits/stdc++.h>
using namespace std;

const int coins[5] {50, 25, 10, 5, 1};
int dp[8000];

int main() {
  //one way of making 0 cents
  dp[0] = 1;
  //bottom-up pre-computation iteration
  //goes through every coin value
  for(int i=0; i<5; i++) {
    //goes through every way
    for(int j=coins[i]; j<8000; j++) {
      //for current add ways
      //ex: i=0, j=50, dp[50] += dp[50-50] which is dp[0] so add 1.
      dp[j] += dp[j-coins[i]];
    }
  }

  int t;
  while(cin >> t) {
    cout << dp[t] << endl;
  }
  return 0;
}
