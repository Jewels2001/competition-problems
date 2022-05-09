/*
By: Julie Wojtiw-Quo
//Unidirectional TSP
Forward recursive DP algorithm to compute the path of minimial weight. Path must
be stored in addition to the dp table (which stores the cost). Path stores the
next row index to go to. Path is sorted by storing the weight and index in
pairs and sorting the vector.
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

vector<vector<int>> dp;
vector<vector<int>> g;
vector<vector<int>> path;
int m, n;

int f(int r, int c) {
  //check if in dp
  if(dp[r][c] != INT_MAX) {
    return dp[r][c];
  }
  //compute resulting choices
  int r1 = ((r - 1) + m) % m;
  int c1 = (c + 1);
  int r2 = (r + 1) % m;
  int a = f(r1, c1);
  int b = f(r, c1);
  int d = f(r2, c1);

  //find min
  //if equal check lexicographic order
  //pair<weight, index>
  vector<pair<int, int>> ugh;
  ugh.push_back(make_pair(a, r1));
  ugh.emplace_back(b, r);
  ugh.emplace_back(d, r2);
  sort(begin(ugh), end(ugh));

  int min = ugh[0].first;
  path[r][c] = ugh[0].second;

  dp[r][c] = g[r][c] + min;
  return dp[r][c];
}

int main() {
  int r, c;
  while(cin >> r >> c) {
    m = r;
    n = c;
    g.clear();
    dp.clear();
    path.clear();
    g.resize(r, vector<int>(c, INT_MAX));
    dp.resize(r, vector<int>(c, INT_MAX));
    path.resize(r, vector<int>(c, INT_MAX));
    for(int i=0; i<r; i++) {
      for(int j=0; j<c; j++) {
        cin >> g[i][j];
      }
    }


    int cost = INT_MAX;
    int start = INT_MAX;
    //fill in base case
    for(int i=0; i<r; i++) {
      dp[i][c-1] = g[i][c-1];
    }

    //run dp
    for(int i=0; i<r; i++) {
      int x = f(i, 0);
      if(x < cost) {
        cost = x;
        start = i;
      }
    }
    //find path and print answer

    cout << start + 1 << " ";
    for(int i=0; i<c-1; i++) {
      cout << path[start][i] + 1 << " ";
      start = path[start][i];
    }

    cout << endl;
    cout << cost << endl;
  }
  return 0;
}
