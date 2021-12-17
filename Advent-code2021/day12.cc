


/* algorithm:
DFS
conditions:
1 go through until hit "end" node, then stop.
2 if a node isLower() then do not go that way again
3 count how many possibilites there are
- > use an array to DP keep track of which paths go where
*/

#include <bits/stdc++.h>
using namespace std;

map<string,int> caves;
vector<vector<int>> G(100); // G(100, vector<int>());
bool small[100];
//bool visited[100];

int ans = 0;

int getCaveNum(string cave) {
  if(caves.find(cave) != caves.end()) {
    return caves[cave];
  }
  else {
    caves.insert(make_pair(cave,caves.size()));
    if(islower(cave[0])) {
      small[caves[cave]] = true;
    } else {
      small[caves[cave]] = false;
    }
    return caves[cave];
  }
}

void dfs(int x, vector<bool> visited) {
  //check if small and visited
  if(small[x] && visited[x]) {
    return;
  }
  //check if at end
  if(getCaveNum("end") == x) {
    ans++;
    return;
  }
  //mark visited
  visited[x] = true;

  //go to next node?
  for(int i=0; i<G[x].size(); i++) { //for (int i : G[x])
    dfs(G[x][i], visited);
  }
}

int main() {

  string cave1;
  string cave2;
  //input +   //create the graph of cave nodes
  while(getline(cin, cave1, '-')) {
    getline(cin, cave2);
    cout << "hi " << cave1 << " " << cave2 << endl;
    int first = getCaveNum(cave1);
    int second = getCaveNum(cave2);
    G[first].push_back(second);
    G[second].push_back(first);
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
