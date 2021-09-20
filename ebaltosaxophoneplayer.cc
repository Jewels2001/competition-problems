#include <bits/stdc++.h>
using namespace std;

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
  string stupidNewline;
  cin >> cases;
  getline(cin, stupidNewline);
  for(int i=0; i<cases;i++) {
    string song;
    getline(cin, song);
    int ans[10]= {0};
    bool pushed[10] = {false};
    int l = song.length();
    if(song.empty()){
      goto label;
    }
    for(int x=0;x<l;x++) {
      for(int j=0;j<10;j++){
        if(notes[buttons[song[x]]][j]){
          if(pushed[j]){
            continue;
          } else {
            ans[j]++;
            pushed[j] = true;
          }
        } else {
          pushed[j] = false;
        }
      }
    }
label:
    for(int k=0;k<10;k++){
      cout << ans[k] << " ";
    }
    cout << endl;
  }
  return 0;
}
