#include <bits/stdc++.h>
using namespace std;

const int S1 = 5; //up and down
const int S2 = 10; //left to right
int a[S1][S2];

vector<int> low;

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
  int height = -1; //a[i][j]
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


int main() {

  //read in input
  char temp;
  for(int i=0; i<S1; i++) {
    for(int j=0; j<S2; j++) {
      cin >> temp;
      a[i][j] = temp - '0';
    }
  }

  //check low points
  //if -1, do not push back
  cout << "all" << endl;
  for(int i=0; i<S1;i++) {
    for(int j=0; j<S2;j++) {

      //check for a given spot, [i-1][j], [i+1][j], [i][j-1], [i][j+1]
      int lowP = check(i, j);
      if(lowP != -1) {
        cout << "i: " << i << " j: " << j << endl;
        low.push_back(lowP);
      }
    }
  }

    //add up for risk value
  int ans = 0;
  for(int i=0;i<low.size();i++) {
    cout << "low: " << low[i] << endl;
    ans += (low[i] +1);
  }
  cout << ans << endl;



  return 0;
}
