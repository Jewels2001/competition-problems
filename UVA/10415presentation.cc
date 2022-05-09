/*
By: Julie Wojtiw-Quo
Used a look-up table to store which buttons are pressed for all the notes.
Immediately checks if the song is empty. Mapped each character button to an index.
Loops through the inputted song notes and checks for every note, whether there is
a corresponding button pushed and if so, checks to see whether it is already pressed
down. If not, adds to the answer and keeps track of the button push.
*/
#include <bits/stdc++.h>
using namespace std;

//look-up table, finger 1 corresponds to notes[0], finger 10 is notes[9]
const int notes[14][10] = {
  {0,1,1,1,0,0,1,1,1,1},
  {0,1,1,1,0,0,1,1,1,0},
  {0,1,1,1,0,0,1,1,0,0},
  {0,1,1,1,0,0,1,0,0,0},
  {0,1,1,1,0,0,0,0,0,0},
  {0,1,1,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0,0,0},
  {1,1,1,1,0,0,1,1,1,0},
  {1,1,1,1,0,0,1,1,0,0},
  {1,1,1,1,0,0,1,0,0,0},
  {1,1,1,1,0,0,0,0,0,0},
  {1,1,1,0,0,0,0,0,0,0},
  {1,1,0,0,0,0,0,0,0,0}
};

map<char,int> buttons = {
  {'c',0},
  {'d',1},
  {'e',2},
  {'f',3},
  {'g',4},
  {'a',5},
  {'b',6},
  {'C',7},
  {'D',8},
  {'E',9},
  {'F',10},
  {'G',11},
  {'A',12},
  {'B',13}
};

int main() {
  int cases;
  cin >> cases;
  cin.ignore();
  while(cases--) {
    string song;
    getline(cin, song);
    if(song.empty()) {
      for(int k=0; k<10; k++) {
        cout << 0 << (10-k == 0 ? "" : " ");
      }
      if(cases) {
        cout << endl;
      }
      continue;
    }

    int ans[10]= {0};
    bool pushed[10] = {false};
    for(int i=0; i<song.length(); i++) {
      for(int j=0; j<10; j++) {
        if(notes[buttons[song[i]]][j]) {
          if(pushed[j]){
            continue;
          } else {
            ans[j]++;
            pushed[j] = true;
          }
        }
        else {
          pushed[j] = false;
        }
      }
    }

    for(int k=0; k<10; k++) {
      cout << ans[k] << (10-k == 0 ? "" : " ");
    }
    if(cases) {
      cout << endl;
    }
  }
  return 0;
}
