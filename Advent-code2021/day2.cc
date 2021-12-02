#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;
const double PI = acos(-1.0);

int main() {
  string a;
  int b;

  int depth = 0;
  int horizontal = 0;

  int one;
  vector<int> data;
  int ans = 0;

  while(cin >> a >> b){

    if(a == "forward") {
      horizontal += b;
    }
    else if(a=="down") {
      depth += b;
    }
    else if(a=="up"){
      depth -= b;
    }
    else {
      cout << "a" << endl;
    }
  }

  cout << horizontal << " " << depth << " " << horizontal*depth << endl;


  return 0;
}
