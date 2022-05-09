/*
By: Julie Wojtiw-Quo
A longest common subsequence problem - using dynamic programing. We have to use
getline because spaces can also represent a city. Then, we run the recursion:
if the dp table has been filled already, we return it; if either i or j == 0
then we return 0 becuase we have gone thorugh the whole string, else we check
whether the letter is the same in both strings: if so, we add one and return the
next letter in both strings, else we return the longest common subsequence
including the letter from one of the strings.
*/
#include <bits/stdc++.h>
using namespace std;

string s1, s2;
vector<vector<int>> dp(101, vector<int>(101, -1));
//return length of largest common subsequence
int f(int i, int j) {
  //already computed
  if(dp[i][j] != -1) {
    return dp[i][j];
  }
  //base case
  if(i == 0 || j == 0) {
    return dp[i][j] = 0;
  }
  //recurxive case
  int ans = 0;
  if(s1[i-1] == s2[j-1]) {
    ans = f(i-1, j-1) + 1;
  }
  else {
    ans = max(f(i-1, j), f(i, j-1));
  }
  //return ans;
  return dp[i][j] = ans;
}

int main() {
  int cases = 1;
  while(getline(cin, s1), s1 != "#") {
    getline(cin, s2);
    for(int i=0; i<=s1.length(); i++) {
      for(int j=0; j<=s2.length(); j++) {
        dp[i][j] = -1;
      }
    }
    cout << "Case #" << cases++ << ": you can visit at most " << f(s1.length(), s2.length())
          << " cities." << endl;

  }
  return 0;
}
