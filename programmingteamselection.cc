
//with cases
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

int main() {
  int m;
  while(cin >> m && m) {
    vector<vector<int>> pairs(m, vector<int>());
    map<string, int> names;
    for(int i=0; i<m; i++) {
      string name1, name2;
      cin >> name1 >> name2;
      if(names.find(name1) != names.end()) {
        names.insert(pair<string, int>(name1, names.size()+1));
      }
      if(names.find(name2) != names.end()) {
        names.insert(pair<string, int>(name2, names.size()+1));
      }
      pairs[names[name1]].push_back(names[name2]);
    }
    if(names.size() % 3 != 0) {
      cout << "impossible" << endl;
      continue;
    }

    for(int i=0; i<pairs.size(); i++) {
      for(int j=0; j<pairs[i].size(); j++) {
        cout<< pairs[i][j] << endl;
      }
      cout << endl;
    }

  }

  return 0;
}
