//given n, return fibonnacci sequence value of n
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

int dp[100];

int f(int n) {
  if(dp[n] != -1) {
    return dp[n];
  }
  // if(n == 0 || n == 1) {
  //   return 1;
  // }
  dp[n] = f(n-1) + f(n-2);
  return dp[n];

}

int main() {
  int n;
  dp[0] = 1;
  dp[1] = 1;
  for(int i=2; i<100; i++) {
    dp[i] = -1;
  }
  while(cin >> n) {
    cout << f(n) << endl;
  }
  return 0;
}
