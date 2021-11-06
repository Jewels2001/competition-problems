#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;

int main() {
  string n;
  cin >> n;

  double white = 0.00;
  double lower = 0.00;
  double upper = 0.00;
  double symbol = 0.00;

  for(int i=0; i<n.length();i++) {
    if(n[i] == 95){
      white++;
    }
    else if((int(n[i]) >= 65) && (int(n[i]) <= 90)) {
      upper++;
    }
    else if((int(n[i]) >= 97) && (int(n[i]) <= 122)) {
      lower++;
    }
    else {
      symbol++;
    }
  }
  cout << (double)white/n.length() << endl << (double)lower/n.length()
    << endl << (double)upper/n.length() << endl << (double)symbol/n.length()
    << endl;

  return 0;
}
