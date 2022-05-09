/*
By: Julie Wojtiw-Quo
A strictly-increasing subsequence problem -> used asc_subseq.cc to find the
'Longest (strictly) ascending/decreasing subsequence.'. Since the input is on
separte lines and we don't know how many missiles there will be, we must use
getline and convert from a string to an int before manipulating the subsequence.
*/

#include <bits/stdc++.h>
using namespace std;
/*
 * Longest Ascending Subsequence
 *
 * Author: Howard Cheng
 * Reference:
 *   Gries, D.  The Science of Programming
 *
 * Given an array of size n, asc_seq returns the length of the longest
 * ascending subsequence, as well as one of the subsequences in S.
 * sasc_seq returns the length of the longest strictly ascending
 * subsequence.  It runs in O(n log n) time.
 *
 * Also included are simplified versions when only the length is needed.
 *
 * Note: If we want to find do the same things with descending
 * subsequences, just reverse the array before calling the routines.
 *
 */

int sasc_seq(vector<int> A, int n, vector<int>& S)
{
  vector<int> last(n+1), pos(n+1), pred(n);
  if (n == 0) {
    return 0;
  }

  int len = 1;
  last[1] = A[pos[1] = 0];

  for (int i = 1; i < n; i++) {
    int j = lower_bound(last.begin()+1, last.begin()+len+1, A[i]) -
      last.begin();
    pred[i] = (j-1 > 0) ? pos[j-1] : -1;
    last[j] = A[pos[j] = i];
    len = max(len, j);
  }

  int start = pos[len];
  for (int i = len-1; i >= 0; i--) {
    S[i] = A[start];
    start = pred[start];
  }

  return len;
}

int main() {
  string temp;
  getline(cin, temp);
  int t = stoi(temp);
  cin.ignore();
  while(t--) {
    string X;
    vector<int> a;
    //input is multiline
    while(getline(cin, X) && X != "") {
      int x = stoi(X);
      a.push_back(x);
    }
    int n = a.size();
    vector<int> s(n);
    //run ascending subsequence code
    int k = sasc_seq(a, n, s);
    //output
    cout << "Max hits: " << k << endl;
    for(int i=0; i<k; i++) {
      cout << s[i] << endl;
    }
    if(t) {
      cout << endl;
    }
  }
  return 0;
}
