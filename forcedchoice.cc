#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, p, s;
  cin >> n >> p >> s;
  for(int i=0;i<s;i++) {
    int m;
    cin >> m;
    bool ans = false;
    for(int j=0;j<m;j++) {
      int temp;
      cin >> temp;
      if(temp == p){
        ans = true;
      }
    }

    cout << (ans ? "KEEP" : "REMOVE") << endl;
  }
  //cout:

  return 0;
}
