#include <iostream>
using namespace std;

int main() {
  char current;
  bool valid = true;
  int** board = nullptr;
  board = new int* [8];
  for(int i = 0; i < 8; i++)
  {
    board[i] = new int [8];
  }
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      board[i][j] = 0;
    }
  }
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      cin >> current;
      if(current == '*'){
        if(board[i][j] == 1) {
          valid = false;
        }else{
          for(int s = 0; s < 8; s++){
            board[i][s] = 1;
            board[s][j] = 1;
            if(i - s >= 0 && j - s >= 0)
              board[i - s][j - s] = 1;
            if(i + s < 8 && j + s < 8)
              board[i + s][j + s] = 1;
            if(i - s >= 0 && j + s < 8)
              board[i - s][j + s] = 1;
            if(i + s < 8 && j - s >= 0)
              board[i + s][j - s] = 1;
          }
        }//else
      }//if
    }
  }
  if(valid == true) {
    cout << "valid";
  }else{
    cout << "invalid";
  }
  for(int i = 0; i < 8; i++)
    delete [] board[i];
  delete[] board;
  board = nullptr;
return 0;
}
