/*
By: Julie Wojtiw-Quo
A simple DFS run through, marking edges as visited and then coloring them.
Also making sure to re-check the start for whether that node also satisfies
the coloring. In this problem, we do not need a visited vector because we can
check if the node has already been colored or not.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g(200, vector<int>(200, 0));
vector<int> colors(200, -1);

int main() {
  int n;
  while(cin >> n, n != 0) {
    int l;
    cin >> l;
    g.clear();
    g.resize(n, vector<int>(n, 0));
    colors.clear();
    colors.resize(n, -1);
    for(int i=0; i<l; i++) {
      int a, b;
      cin >> a >> b;
      g[a][b] = b;
      g[b][a] = a;
    }

    colors[0] = 0;
    int curr = 0;
    bool bipartite = true;
    //dfs
    stack<int> S;
    S.push(0);
    while(!S.empty() && bipartite) {
      int curr = S.top(); S.pop();
      //do something to curr
      // for all neighbours w of curr
      for(int i=0; i<g[curr].size(); i++) {
        int w = g[curr][i];
        if(w == 0) {
          continue;
        }
        //do something to neighbours
        if(colors[i] == colors[curr]) {
          bipartite = false;
          break;
        }
          if(colors[i] == -1) {
            colors[i] = 1-colors[curr];
            S.push(i);
          }
      }
    }

    cout << (bipartite ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
  }
  return 0;
}
