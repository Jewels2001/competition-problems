#include <bits/stdc++.h>
using namespace std;


int main() {
  int ans = 0;
  vector<int> crabs;
  int a;
  char t;
  //add , onto end of input
  while(cin >> a >> t) {
    crabs.push_back(a);
  }
  sort(crabs.begin(), crabs.end());

  double median;
  if((crabs.size() /2) % 2) {
    median = (crabs[crabs.size()/2] + crabs[(crabs.size()/2)-1]) / 2;
  }
  else {
    median = crabs[crabs.size()/2];
  }

  for(int i=0; i<crabs.size();i++) {
      if(crabs[i] < median) {
        ans+= median - crabs[i];
      }
      else if(crabs[i] > median) {
        ans+= crabs[i] - median;
      }
  }
  cout << ans << endl;
  return 0;
}
