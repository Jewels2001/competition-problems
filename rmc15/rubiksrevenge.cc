/*
By: Julie Wojtiw-Quo
A standard state search problem - running regular bfs was too slow, but since
every configuration can be found in less than 13 moves, I ran bfs from the end
for 6 moves/half and then ran bfs from the input until I reached a state that
was previously seen.
*/
#include <bits/stdc++.h>
using namespace std;

string goal = "RRRRGGGGBBBBYYYY";
string puzzle = "";

//number of states: 16 spots with 4 colors each with 4 direction
//so 16! / (4!)^4 = 63000000
// nodes for every state

vector<vector<int>> graph;
vector<vector<int>> dist;
map<string, int> distF;
map<string, int> distB;

//each square has 4 directions, 16 squares = 16*4 = 64*
//'R' = 0, 'G' = 1, 'B' = 2, 'Y' = 3
//id = square

string moveR(string old, int row, int d) {
  //if row = 0, 0-3, row = 1, 4-7, row = 2, 8-11, row = 3, 12-15
  //negative d is left, pos is right
  string s = old;
  int index = row*4;
  string temp = old.substr(index, 4);
  if(d == -1) {
    s[index] = temp[1];
    s[index+1] = temp[2];
    s[index+2] = temp[3];
    s[index+3] = temp[0];
  } else {
    s[index] = temp[3];
    s[index+1] = temp[0];
    s[index+2] = temp[1];
    s[index+3] = temp[2];
  }
  return s;
}

string moveC(string old, int col, int d) {
  //col 0 = 0,4,8,12  col1 = 1,5,9,13  col2=2,6,10,14  col3=3,7,11,15
  //negative d is down, pos is up
  string s = old;
  string temp = "";
  if(d == -1) {
    s[col] = old[col+12];
    s[col+4] = old[col];
    s[col+8] = old[col+4];
    s[col+12] = old[col+8];
  } else {
    s[col] = old[col+4];
    s[col+4] = old[col+8];
    s[col+8] = old[col+12];
    s[col+12] = old[col];
  }
  return s;
}

void bfsB(string start) {
  //only run up to 6 moves/half
  queue<string> q;
  int dist = 0;
  q.push(start);
  distB[start] = 0;


  while(!q.empty()) {
    //move backwards one step
    string first = q.front(); q.pop();
    dist = distB[first];
    if(dist > 5) {
      break;
    }
    //addNodesCheck()
    // add all 4 directions possible for all 4 rows + cols
    for(int i=0; i<4; i++) {
      string a = moveR(first, i, -1);
      string b = moveR(first, i, 1);
      string c = moveC(first, i, -1);
      string d = moveC(first, i, 1);
      //check if dist is added, if not add dist
      if(distB.find(a) == distB.end()) {
        distB[a] = dist+1;
        q.push(a);
      }
      if(distB.find(b) == distB.end()) {
        distB[b] = dist+1;
        q.push(b);
      }
      if(distB.find(c) == distB.end()) {
        distB[c] = dist+1;
        q.push(c);
      }
      if(distB.find(d) == distB.end()) {
        distB[d] = dist+1;
        q.push(d);
      }
    }
  }

}

int bfsF(string start) {
  queue<string> q;
  int dist = 0;
  q.push(start);
  distF[start] = 0;

  while(!q.empty()) {
    //move backwards one step
    string first = q.front(); q.pop();
    dist = distF[first];
    //check for state in other map from the end
    if(distB.find(first) != distB.end()) {
      return dist+distB[first];
    }
    //addNodesCheck()
    // add all 4 directions possible for all 4 rows + cols
    for(int i=0; i<4; i++) {
      string a = moveR(first, i, -1);
      string b = moveR(first, i, 1);
      string c = moveC(first, i, -1);
      string d = moveC(first, i, 1);
      //check if dist is added, if not add dist
      if(distF.find(a) == distF.end()) {
        distF[a] = dist+1;
        q.push(a);
      }
      if(distF.find(b) == distF.end()) {
        distF[b] = dist+1;
        q.push(b);
      }
      if(distF.find(c) == distF.end()) {
        distF[c] = dist+1;
        q.push(c);
      }
      if(distF.find(d) == distF.end()) {
        distF[d] = dist+1;
        q.push(d);
      }
    }
  }
  return dist;
}

int main() {
  for(int i=0; i<16; i++) {
    char temp;
    cin >> temp;
    puzzle += temp;
  }
  if(puzzle == goal) {
    cout << "0" << endl;
    return 0;
  }
  bfsB(goal);
  int ans = bfsF(puzzle);
  cout << ans << endl;

  return 0;
}
