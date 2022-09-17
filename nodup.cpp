#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000


int main() {
  string a;
  getline(cin, a);
  for(int i=0; i<a.size(); i++) {
    a[i] = toupper(a[i]);
  }
  map<string, int> m;
  stringstream ss(a);
  string test;
  while(ss >> test) {
    if(m.find(test) != m.end()) {
      m[test]++;
    } else {
      m.insert(pair<string, int>(test, 1));
    }
  }
  bool dupes = false;
  for(auto a : m) {
    if(a.second > 1) {
      dupes = true;
      break;
    }
  }
  // no == one or more words repeat, // yes == no word repeated
  cout << (dupes ? "no" : "yes") << endl;

  return 0;
}
