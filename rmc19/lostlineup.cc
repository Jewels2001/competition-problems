/*
By: Julie Wojtiw-Quo
Basic implementation, storing the inputted number + 2 in order to account for
Jimmy and the fact that their position is +1 to the number of people between.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> line (n);
  line[0] = 1;
  for(int i=0;i<n-1;i++) {
    int temp;
    cin >> temp;
    line[temp+1] = i+2;
  }
  for(int i=0;i<n;i++) {
    cout << line[i] << " ";
  }
  return 0;
}
