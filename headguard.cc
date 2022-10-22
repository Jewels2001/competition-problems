#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000


int main() {

  string l;
  while(getline(cin, l)) {
    vector<pair<char, int>> chars;
    int s = 0;
    int current = 0;
    for(int i=0; i<l.length(); i++) {
      if(s == 0) {
        chars.push_back(make_pair(l[i], 1));
        s = chars.size();
        continue;
      }
      if(l[i] == chars[current].first) {
        chars[current].second++;
      } else {
        chars.push_back(make_pair(l[i], 1));
        current++;
        s = chars.size();
      }
    }

    for(int j=0; j<chars.size(); j++) {
      cout << chars[j].second << chars[j].first;
    }
    cout << endl;
  }

  return 0;
}
