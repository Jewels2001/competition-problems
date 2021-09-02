#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;

  priority_queue<int> p;
  vector<pair<int,int>> v;
  // <time, money>
  int max = 0;

  for(int i=0; i<n;i++) {
    pair<int,int> t;
    cin >> t.second >> t.first;
    v.push_back(t);
  }
  sort(v.rbegin(), v.rend());

  int index = 0;
  while(t--) {
    while(v[index].first == t) {
      p.push(v[index].second);
      index++;
    }
    if(!p.empty()) {
      max += p.top();
      p.pop();
    }
  }

  cout << max;
  return 0;
}
