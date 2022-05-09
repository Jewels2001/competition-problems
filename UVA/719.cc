/*
By: Julie Wojtiw-Quo
Suffix array - finds the rotation of the letters that is lexicographically
smallest. We concatenate the string onto itself so that all rotations are present;
then we go through the string and compare the suffixes to find the least
lexicographical one. After that, we make sure that suffix is at least length n,
and output the first position.
*/

#include <bits/stdc++.h>
using namespace std;
/*
 * Finding the lexicographically least rotation of a string, and finding
 * the smallest period of a string.
 *
 * Author: Sumudu Fernando
 *
 * Given a string, the algorithm can be used to compute two things:
 *
 *   a) the position at which the lexicographically least rotation starts.
 *      If there are ties, give the first position.
 *   b) the length of the shortest substring such that the original string
 *      is a concatenation of copies of that substring
 *
 * Complexity: O(n) where n = length of the string
 *
 * Tested on: 719            Glass Beads
 *            10298          Power Strings
 *            ACPC 2011 H    Let's call a SPaDE a SPaDE
 */

// pos = position of the start of the lexicographically least rotation
// period = the period
void compute(string s, int &pos, int &period)
{
  s += s;
  int len = s.length();
  int i = 0, j = 1;
  for (int k = 0; i+k < len && j+k < len; k++) {
    if (s[i+k] > s[j+k]) {
      i = max(i+k+1, j+1);
      k = -1;
    } else if (s[i+k] < s[j+k]) {
      j = max(j+k+1, i+1);
      k = -1;
    }
  }

  pos = min(i, j);
  period = (i > j) ? i - j : j - i;
}


int main() {
  int n;
  cin >> n;
  while(n--) {
    string s;
    int pos, period;
    cin >> s;
    compute(s, pos, period);
    cout << pos+1 << endl;
  }
  return 0;
}
