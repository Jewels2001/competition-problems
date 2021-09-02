#include <bits/stdc++.h>
using namespace std;

int main() {
  int cases;
  cin >> cases;
  for(int i=0; i<cases;i++) {
    int n;
    cin >> n;

    int votes =0;
    pair<int, int> winner = make_pair(0,0);

    bool same = false;
    for(int j=1; j<n+1;j++) {
      int temp;
      cin >> temp;
      if(temp > winner.first) {
        winner.first = temp;
        winner.second =j;
        same = false;
      }
      else if(temp == winner.first) {
        same = true;
      }
      votes += temp;
    }
    if(same) {
      cout << "no winner" << endl;
    }
    else {
      cout << ((winner.first > votes/2) ? "majority " : "minority ") << "winner " << winner.second << endl;
    }
  }
  return 0;
}
