#include <bits/stdc++.h>
using namespace std;



bool checkBoard(vector<vector<pair<int, bool>>>& board) {
  //check rows bingo for one board
  for(int j=0; j<5;j++) {
    int rowCheck = 0;
    for(int k=0; k<5;k++) {
      if(board[j][k].second == true) {
        rowCheck++;
      }
    }
    if(rowCheck == 5) {
      return true;
    }
  }
  //check cols bingo for one board
  for(int j=0; j<5;j++) {
    int colCheck = 0;
    for(int k=0; k<5;k++) {
      if(board[k][j].second == true) {
        colCheck++;
      }
    }
    if(colCheck == 5) {
      return true;
    }
  }
  return false;
}


int main() {
  string a;
  int b;

  vector<vector<vector<pair<int, bool>>>> bingo;
  stringstream ss;

  string calls;
  cin >> calls;
  calls.push_back(',');
  ss << calls;

  while(cin >> b) {
    vector<vector<pair<int, bool>>> board;
    //(5, vector<pair<int,bool>>(5));
    for(int i=0;i<5;i++) {
      vector<pair<int,bool>> tempVec;
      //(5, pair<int,bool>(5));
      for(int j=0;j<5;j++) {
        if(i==0 && j==0){
          pair<int, bool> tempPair = make_pair(b, false);
          tempVec.push_back(tempPair);
        }
        else {
          cin >> b;
          pair<int, bool> tempPair = make_pair(b, false);
          tempVec.push_back(tempPair);
        }
      }
      board.push_back(tempVec);
    }
    bingo.push_back(board);
  }

  int boardNum = bingo.size();


  int num;
  char temp;
  int winner = -1;
  set<int> last;
  while(ss >> num >> temp) {
    bool win = false;
    //stringstream
    for(int i=0; i<boardNum;i++) {
      // vector<vector<pair<int, bool>>> board = bingo[i];

      //marks num for one board
      for(int j=0; j<5;j++) {
        //vector<pair<int, bool>> row = board[j];
        for(int k=0; k<5;k++) {
          if(bingo[i][j][k].first == num) {
            bingo[i][j][k].second = true;
          }
        }
      }
      //check if board has won
      if(checkBoard(bingo[i])) {
        winner = i;
        if(last.find(winner) == last.end()) {
          last.insert(winner);
          cout << "winner: " << winner << endl;
        }
        // break;
      }
      if(last.size() == bingo.size()) {
        win = true;
        break;
      }
    }
    if(win) {
      break;
    }
  }

  vector<vector<pair<int, bool>>> board = bingo[winner];
  int sum = 0;
  for(int i=0; i<5; i++) {
    for(int j=0; j<5; j++) {
      if(board[i][j].second == false) {
        sum += board[i][j].first;
      }
    }
  }
  cout << "sum: " << sum << " num: " << num << endl;
  cout << "sum * num: " << sum*num << endl;

  return 0;
}
