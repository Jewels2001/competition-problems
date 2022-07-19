#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000


int main() {
  map<string, int> m;
  string s;
  while(getline(cin, s) && s != "***") {
    if(!m.insert(std::pair<string, int>(s, 1)).second) {
      m[s]++;
    }
  }
  int curr_max = 0;
  string name = "";
  bool multiple = false;
  for(auto x : m) {
    if(x.second > curr_max) {
      name = x.first;
      curr_max = x.second;
    }
    else if(x.second == curr_max) {
      multiple = true;
    }
  }

  if(!multiple) {
    cout << name << endl;
  } else {
    cout << "Runoff!" << endl;
  }

  return 0;
}
