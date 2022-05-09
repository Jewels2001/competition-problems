/*
By: Julie Wojtiw-Quo
Takes in bounds, immediately checks count for empty line between outputs. Uses
vector with padding around bounds, and look-up table for coordinates around
the mines.
*/
#include <bits/stdc++.h>
using namespace std;

int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
  int n, m;
  int count = 0;
  while(cin >> n >> m, n != 0 && m != 0) {
    if (count) {
      cout << endl;
    }
    vector<vector<char>> grid(n+2, vector<char>(m+2, '0'));
    //read in input
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
        cin >> grid[i][j];
        if(grid[i][j] == '.') {
          grid[i][j] = '0';
        }
      }
    }

    for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
        if(grid[i][j] == '*') {
          for(int k=0; k<8; k++) {
            int i2 = i+di[k];
            int j2 = j+dj[k];
            if(grid[i2][j2] != '*') {
              grid[i2][j2]++;
            }
          }
        }
      }
    }

    cout << "Field #" << ++count << ":" << endl;
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
        cout << grid[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}
