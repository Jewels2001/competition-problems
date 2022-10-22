#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000


int main() {
  int n;
  cin >> n;
  string temp;
  getline(cin, temp);

  int attend = 0;
  for(int i=0; i<n; i++) {
    string color;
    getline(cin, color);
    for(int j=0; j<color.length(); j++) {
      color[j] = tolower(color[j]);
    }
    if(color.find("pink")!=string::npos || color.find("rose")!=string::npos) {
      attend++;
    }
  }

  cout << (attend == 0 ? "I must watch Star Wars with my daughter" : to_string(attend)) << endl;

  return 0;
}
