#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;
const double PI = acos(-1.0);

int main() {
  int a, b, t, ta, tb, c;
  cin >> a >> b >> t >> ta >> tb;
  int ans = 0;
  cin >> c;

  int highestA = a + (t/ta);
  int highestB = b + (t/tb);

  vector<pair<int, int>> v;
  //tech, busniess
  priority_queue<int> p;

  for(int i=1; i<=c; i++) {
    pair<int,int> t;
    cin >> t.first >> t.second;
    // if((t.first <= a) && (t.second <= b)) {
    //   ans++;
    // }
    // else {
      v.push_back(t);
    // }
  }

  sort(begin(v), end(v));

  int newB = b;
  int timeLeft = t;

  for(int i=0; i<v.size();i++) {
    int needA = v[i].first - a;
    int needB = v[i].second - b;
    if((v[i].first <= a) && v[i].second <= b) {
      p.push(b);
      continue;
    }
    if((v[i].first > highestA) || (v[i].second > highestB)) {
      //(v[i].first - a) > t/ta
      continue;
    }

    timeLeft -= (needA*ta);
    newB += needB;
    if((b <= newB) && (timeLeft >= needB*tb)) {
      p.push(b);
    }
    while(!p.empty() && p.top() > newB) {
      p.pop();
    }

  }
  ans = max(ans, (int)p.size());

  cout << ans << endl;
  return 0;
}
