#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;

int main() {
  int cases;
  cin >> cases;
  for(int i=1; i<cases+1;i++) {
    int n;
    set<int> guests;
    cin >> n;
    for(int j=0; j<n; j++){
      int temp;
      cin >> temp;
      auto p = guests.insert(temp);
      if(!p.second){
        guests.erase(p.first);
      }
    }
    cout << "Case #" << i << ": " << *guests.begin() << endl;
  }
  return 0;
}
