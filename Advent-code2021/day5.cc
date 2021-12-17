#include <bits/stdc++.h>
using namespace std;

void fillVerticalLine(vector<vector<int>>& data, int x, int y1, int y2) {

  for(int i=min(y1, y2);i<=max(y2, y1);i++) {
    data[i][x]++;
  }
}

void fillHorizontalLine(vector<vector<int>>& data, int y, int x1, int x2) {

  for(int i=min(x1, x2);i<=max(x2, x1);i++) {
    data[y][i]++;
  }
}

int main() {
  string a;
  int b;

  vector<vector<int>> data (1000, vector<int>(1000, 0));
  int ans = 0;

  int x1, y1, x2, y2;
  char temp;

  while(getline(cin, a)) {
      istringstream ss(a);
      ss >> x1 >> temp >> y1 >> temp >> temp >> x2 >> temp >> y2;
      if(x1 == x2) {
        fillVerticalLine(data, x1, y1, y2);
      }
      else if(y1 == y2) {
        fillHorizontalLine(data, y1, x1, x2);
      }
  }
  for(int i=0; i<1000; i++) {
    for(int j=0; j<1000; j++) {
      if(data[i][j] >= 2) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
