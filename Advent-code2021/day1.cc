//with cases
#include <bits/stdc++.h>
using namespace std;

int main() {
  int one;
  vector<int> data;
  int ans = 0;

  //end-of-file input on windows is ctrl-z
  do{
    cin >> one;
    data.push_back(one);
  } while (one);

  int a = data.size();
  int lastSeen = data[0];
  for(int i=1; i<a; i++) {
    int next = data[i];
    if(next > lastSeen) {
      ans++;
    }
    lastSeen = data[i];
  }
  cout << ans << endl;
  return 0;
}
