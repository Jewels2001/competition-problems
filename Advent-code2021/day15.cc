#include <bits/stdc++.h>
using namespace std;

map<string,int> caves;
int G[100][100]; // adj. matrix
bool small[100];
//bool visited[100];

int ans = 0;

// int getCaveNum(string cave) {
//   if(caves.find(cave) != caves.end()) {
//     return caves[cave];
//   }
//   else {
//     caves.insert(make_pair(cave,caves.size()));
//     if(islower(cave[0])) {
//       small[caves[cave]] = true;
//     } else {
//       small[caves[cave]] = false;
//     }
//     return caves[cave];
//   }
// }
//
// void dfs(int x, vector<bool> visited) {
//   //check if small and visited
//   if(small[x] && visited[x]) {
//     return;
//   }
//   //check if at end
//   if(getCaveNum("end") == x) {
//     ans++;
//     return;
//   }
//   //mark visited
//   visited[x] = true;
//
//   //go to next node?
//   for(int i=0; i<G[x].size(); i++) { //for (int i : G[x])
//     dfs(G[x][i], visited);
//   }
// }

int b

int main() {

  string cave1;
  int num;
  stringstream a;
  //input +   //create the graph of cave nodes

    for(int i=0; i<100; i++) {
      while(getline(cin, cave1)) {
        stringstream a(cave1);
        for(int j=0; j<100; j++) {
          a << num;
          G[i][j] = num;
        }
      }
    }
  //go through the graph + count
  vector<bool> visits (caves.size(), false);
  dfs(getCaveNum("start"), visits);
  //output answer
  cout << ans << endl;

  //debug
  // for(auto p : caves) {
  //   cout << p.first << " " << p.second << endl;
  // }



  return 0;

}
