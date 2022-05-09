/*
By: Julie Wojtiw-Quo
Exhaustively searches the board for possible answers, storing the current board
state in arrays. Checks and ignores bad placements before recursively checking
subsequent rows and then columns.
*/
#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int n = 1;
vector<vector<char>> board(n, vector<char>(n));

void queens(int rowPos[15], bool col[15], bool diag1[30], bool diag2[30], int i) {
  if (i == n) {
    ans++;
    return;
  }
  for(int c=0; c<n; c++) {
    //try (r,c)
    rowPos[i] = c;
    //if bad[r][c] skip
    if(board[i][c] == '*') {
      continue;
    }
    //if same col, diag1, diag2 skip O(1)
    if(col[c] || diag1[i-c+n] || diag2[i+c]) {
      continue;
    }
    //mark col, diag1, diag2 as occupied
    col[c] = 1;
    diag1[i-c+n] = 1;
    diag2[i+c] = 1;

    queens(rowPos, col, diag1, diag2, i+1);

    //unmark everything
    col[c] = 0;
    rowPos[i] = 0;
    diag1[i-c +n] = 0;
    diag2[i+c] = 0;
  }
}


int main() {
  int cases = 1;
  while(cin >> n && n != 0) {
    board.resize(n, vector<char>(n));
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        cin >> board[i][j];
      }
    }

    int row[15] = {0};
    bool col[15] = {0};
    bool diag1[30] = {0};
    bool diag2[30] = {0};

    queens(row, col, diag1, diag2, 0);

    cout << "Case " << cases << ": " << ans << endl;
    cases++;
    ans = 0;
  }
  return 0;
}
