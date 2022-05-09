/*
By: Julie Wojtiw-Quo
Exhaustively searches numbers 0000 - 9999 for the correct guess(es). First
checks whether the digit exists in both, and then adjusts ratio for the digits
that exist in both and are in the correct position. A set does not work because
there is no way to subtract the duplicates (ie, exists and correct pos). Once
there are 2 correct codes, search breaks for efficiency.
*/

#include <bits/stdc++.h>
using namespace std;

int counter = 0;
int ans = 0;
string strans = "";

void make4(string& a) {
  while(a.length() < 4) {
    a.insert(begin(a), '0');
  }
}

void solve(const vector<string>& c, const vector<pair<int, int>>& d) {
  int g = c.size();
  for(int i=0;i<10000;i++) {
    string start = to_string(i);
    make4(start);
    int k = 0, j = 0;

    for(j=0; j<g; j++) {
      int code[10] = {};
      int a = 0, b = 0;
      //adds number of each digit to array
      for(k=0; k<4; k++) {
        code[start[k]-'0']++;
      }
      //checks if num exists
      for(k=0; k<4; k++) {
        if(code[c[j][k]-'0'] > 0) {
          code[c[j][k]-'0']--;
          b++;
        }
      }
      //checks if num is equal
      for(k=0; k<4; k++) {
        if(start[k] == c[j][k]) {
          a++;
          b--;
        }
      }
      //checks if is solution
      if(d[j].first == a && d[j].second == b) {
        continue;
      }
      else {
        break;
      }
    }
    if(j == g) {
      counter++;
      ans = i;
      strans = start;
      if(counter >= 2) {
        break;
      }
    }
  }
}

int main() {
  int cases;
  cin >> cases;
  while(cases--) {
    int g;
    cin >> g;
    if(g == 0) {
      cout << "impossible" << endl;
    }
    vector<pair<int, int>> d(g);
    vector<string> c(g);
    for(int i=0; i<g; i++) {
      char temp;
      cin >> c[i];
      cin >> d[i].first >> temp >> d[i].second;
    }
    counter = 0;
    ans = 0;
    solve(c, d);

    if(counter == 1) {
      cout << strans << endl;
    }
    else if(counter >= 2) {
      cout << "indeterminate" << endl;
    }
    else {
      cout << "impossible" << endl;
    }
  }
  return 0;
}
