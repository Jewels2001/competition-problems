/*
By: Julie Wojtiw-Quo
First checks impossible cases by recreating the 0/1 grid given the positions of
the 1s in the input grid. If the expected grid is different than the input, then
the input is impossible. If input is 0, button is N. Otherwise, if two or more
1s are present in both the row and the column for a button, it is I, else P. 
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> grid;
int r, c;

bool checkVertical(const vector<string>& g, const int& r, const int& i, const int& j) {
  for(int n=0;n<r;n++) {
    if(n == i) {
      continue;
    }
    if(g[n][j] == '1') {
      return true;
    }
  }
  return false;
}
bool checkHorizontal(const vector<string>& g, const int& c, const int& i, const int& j) {
  for(int n=0; n<c;n++) {
    if(n == j)  {
      continue;
    }
    if(g[i][n] == '1') {
      return true;
    }
  }
  return false;
}

bool checkImpossible() {
  set<int> row, col;
  vector<string> temp (r, "");
  //put locations of turned on wires in set
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) {
      if(grid[i][j] == '1') {
        row.insert(i);
        col.insert(j);
      }
    }
  }
  //create 0/1 grid based on turned on wires
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) {
      if(row.find(i) != row.end() && col.find(j) != col.end()) {
        temp[i] += '1';
      }
      else {
        temp[i] += '0';
      }
    }
  }
  //compare new 0/1 grid to input
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) {
      if(grid[i][j] != temp[i][j]) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int cases;
  cin >> cases;
  while(cases--) {
    cin >> r >> c;
    cin.ignore(100, '\n');
    grid.resize(r);
    for(int i=0;i<r;i++) {
      getline(cin, grid[i]);
    }
    //first check impossible
    if(checkImpossible()) {
      cout << "impossible" << endl;
      cout<< "----------" << endl;
      continue;
    }
    //check multiple in row && column
    for(int j=0;j<r;j++){
      string ans = "";
      for(int k=0; k<c;k++) {
        bool row = false;
        bool col = false;
        if(grid[j][k] == '0') {
          ans += 'N';
        }
        else if(grid[j][k] == '1') {
          row = checkHorizontal(grid, c, j, k);
          col = checkVertical(grid, r, j, k);
          if(row && col) {
            ans += 'I';
          }
          else {
            ans += 'P';
          }
        }
      }
      cout << ans << endl;
    }

    cout<< "----------" << endl;
  }
  return 0;
}
