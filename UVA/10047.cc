/*
By: Julie Wojtiw-Quo
BFS after building a graph with nodes for every color and direction. Keeps track
of row/col values, direction, and color for every node. Up to 12500 nodes if
maximum bouds. Graph connects every node that isn't a # to each other. Then, BFS
uses distance vector to track time and node look up function allows us to find
the end nodes no matter where they are.
*/

//Nodes: (r, c, d, color)
//coordinates  r,c
//direction d
//color c = (color +1) % 5
// right d = (d+1) % 4
// left d = (d+3) % 4

//maximum 25*25*20 nodes = 12500 nodes

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> g;
vector<vector<int>> graph;
int m, n;
//dist[r,c,d,color];

//down, left, up, right  (south, west, north, east)
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};

//from 0 - max 12500 nodes
int getNodeID(int r, int c, int d, int color) {
  return (color + (5*d) + (20*c) + 20*n*r);
  //(5d + color) + 20c +20*m*r
  //one color -> 4 possible directions -> 20 possible row spots ->
  //20*n nodes per row
}

//bigger than or equal to 0, less than size
bool boundsCheck(int i, int j) {
  return (i >= 0 && j >= 0 && i < m && j < n);
}


int main() {
  int cases = 1;
  while(cin >> m >> n, n != 0 && m != 0) {
    g.clear();
    g.resize(m, vector<char>(n));
    graph.clear();
    graph.resize(20*m*n);
    //read in grid
    for(int i=0; i<m; i++) {
      for(int j=0; j<n; j++) {
        cin >> g[i][j];
      }
    }
    //create graph
    //every '.' has 4 directions
    //every direction has 5 colors
    //for one '.', the same color will be connected in adjacent directions
    int start;
    set<int> end;
    for(int i=0; i<m; i++) {
      for(int j=0; j<n; j++) {
        if(g[i][j] == '#') {
          continue;
        }
        //get start node
        if(g[i][j] == 'S') {
          start = getNodeID(i, j, 2, 0);
        }
        //get ends (4 directions possible)
        if(g[i][j] == 'T') {
          for(int k=0; k<4; k++) {
            end.insert(getNodeID(i, j, k, 0));
          }
        }

        // for every color
        for(int k=0;k<5;k++) {
          // for every direction
          for(int l=0;l<4;l++) {
              int id = getNodeID(i, j, l, k);
              // right d = (d+1) % 4
              graph[id].push_back(getNodeID(i, j, ((l+1) %4), k));
              // left d = (d+3) % 4
              graph[id].push_back(getNodeID(i, j, ((l+3)%4), k));
              // forward r+dr[d], c+dc[d]
              // color = (color + 1) % 5
              int i2 = i+dr[l];
              int j2 = j+dc[l];
              // check out of bounds, check hash
              if(boundsCheck(i2, j2) && g[i2][j2] != '#') {
                graph[id].push_back(getNodeID(i2, j2, l, ((k+1)%5)));
              }
          }
        }

      }
    }
    //BFS
    bool reachable = false;
    vector<int> distance(20*m*n, -1);
    queue<int> Q;
    Q.push(start);
    distance[start] = 0;
    while(!Q.empty()) {
      int curr = Q.front(); Q.pop();
      // do something to curr

      for(int w : graph[curr]) {
        // add if node -1
        if(distance[w] == -1) {
          Q.push(w);
          distance[w] = distance[curr] + 1;
        }
        // add if node is bigger
        else if(distance[w] > distance[curr] + 1) {
          Q.push(w);
          distance[w] = distance[curr] + 1;
        }
        // if smaller, don't care
      }
    }

    cout << "Case #" << cases++ << endl;
    int ans = INT_MAX;
    for(int i : end) {
      if(distance[i] != -1) {
        ans = min(ans, distance[i]);
      }
    }
    cout << ((ans == INT_MAX) ? "destination not reachable" : "minimum time = " + to_string(ans) + " sec");
    cout << endl << endl;
  }
  return 0;
}
