#include <bits/stdc++.h>
using namespace std;

const int S1 = 100; //up and down
const int S2 = 100; //left to right
int a[S1][S2];
bool visited[S1*S2];

vector<vector<int>> G(S1*S2);

vector<int> low;
vector<int> lowIDs;
vector<int> basins;

int dx[4] = {-1,0,1,0}; //left to right
int dy[4] = {0,-1,0,1}; // up and down

int getID(int i, int j) {
  return ((i*S2) + j);
}

bool bounds(int i, int j) {
  if((i < 0) || (i >= S1)) {
    return false;
  }
  if((j < 0) || (j >= S2)) {
    return false;
  }
  return true;
}

int check(int i, int j) {
  //check for a given spot, [i-1][j], [i+1][j], [i][j-1], [i][j+1]
  int height = -1;
  bool all = true;

  //check [i-1][j]
  bool inBounds = bounds(i-1, j);
  if(inBounds) {
    if(a[i][j] >= a[i-1][j]) {
      return -1;
    }
  }
  //check [i+1][j]
  inBounds = bounds(i+1, j);
  if(inBounds) {
    if(a[i][j] >= a[i+1][j]) {
      return -1;
    }
  }
  //check [i][j-1]
  inBounds = bounds(i, j-1);
  if(inBounds) {
    if(a[i][j] >= a[i][j-1]) {
      return -1;
    }
  }
  inBounds = bounds(i, j+1);
  if(inBounds) {
    if(a[i][j] >= a[i][j+1]) {
      return -1;
    }
  }
  return a[i][j];
}


int dfs(int source) {
  //check if visited
  if(visited[source]) {
    return 0;
  }
  //set it to visited
  visited[source] = true;

  int ans = 1;
  //go dfs
  for(int k=0; k<G[source].size();k++) {
    ans += dfs(G[source][k]); //for(auto i : G[source]) { dfs(i)}
  }
  return ans;
}



int main() {

  //read in input
  char temp;
  for(int i=0; i<S1; i++) {
    for(int j=0; j<S2; j++) {
      cin >> temp;
      a[i][j] = temp - '0';
    }
  }

  //find low points
  //if -1, do not push back
  cout << "all" << endl;
  for(int i=0; i<S1;i++) {
    for(int j=0; j<S2;j++) {

      //check for a given spot, [i-1][j], [i+1][j], [i][j-1], [i][j+1]
      int lowP = check(i, j);
      if(lowP != -1) {
        cout << "i: " << i << " j: " << j << endl;
        low.push_back(lowP);
        lowIDs.push_back(getID(i, j));
        // //take low point and expand outwards for size of basin
        // basins.push_back(checkBasin(i, j, lowP));
      }
    }
  }

  // for(int i=0; i<lowIDs.size();i++) {
  //   for(int j=0;j<lowIDs.size();j++) {
  //     cout << "lowID: " << lowIDs[i];
  //   }
  // }

  //make graph

  //rules to add
  // - in bounds
  // - greater or equal to
  // - not nine
  cout << "graph time" << endl << endl;
  for(int i=0; i<S1;i++) {
    for(int j=0; j<S2;j++) {
      //check not nine
      if(a[S1][S2] == 9) {
        continue;
      }
      //check neighbours
      for(int k=0;k<4;k++) {
        int i2 = i+dy[k];
        int j2 = j+dx[k];
        if(bounds(i2, j2)) {
          //check not nine and greater
          if(a[i2][j2] != 9 && a[i2][j2] >= a[i][j]) {
            //add edge
            G[getID(i,j)].push_back(getID(i2,j2));
          }
        }
      }
    }
  }

  //dfs from low points
  for(int i=0; i<lowIDs.size();i++) {
    for(int a=0;a<S1*S2;a++) {
        visited[a] = false;
    }
    basins.push_back(dfs(lowIDs[i]));
  }

  for(int i : basins) {
    cout << "basin: " << i << endl;
  }

  //go through and find max
  sort(basins.rbegin(), basins.rend());

    //add up for sizes
  int la = 1;
  for(int i=0;i<3;i++) {
    la *= basins[i];
  }
  cout << "the multiplied size" << la << endl;

  return 0;
}
