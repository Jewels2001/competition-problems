/*
By: Julie Wojtiw-Quo
Goes through input looking for greatest num of votes (winner) as well as keeps
a running total of the votes. If the winner is strictly greater than the num of
votes / 2, then they are majority, else minority. If the current winner has the
same number of votes as someone else, then there is no winner.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, total = 0;
    pair<int, int> winner = make_pair(0, 0);
    bool same = false;
    cin >> n;
    for(int i=0; i<n; i++) {
      int temp;
      cin >> temp;
      total += temp;
      if(temp > winner.first) {
        winner.first = temp;
        winner.second = i;
        same = false;
      }
      else if(temp == winner.first) {
        same = true;
      }
    }
    if(same) {
      cout << "no winner" << endl;
    }
    else {
      cout << ((winner.first > total/2) ? "majority " : "minority ") <<
              "winner " << winner.second+1 << endl;
    }
  }
  return 0;
}
