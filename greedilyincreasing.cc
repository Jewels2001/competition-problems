#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> gis;
  int last = 0;
  for(int i=0; i<n; i++) {
    int temp;
    cin >> temp;
    if(temp > last) {
      gis.push_back(temp);
      last = temp;
    }
  }
  cout << gis.size() << endl;
  for(unsigned int j=0; j<gis.size(); j++) {
    cout << gis[j] << " ";
  }

  return 0;
}
