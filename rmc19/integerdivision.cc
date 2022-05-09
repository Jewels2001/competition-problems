/*
By: Julie Wojtiw-Quo
Mapped the possible integer division results as keys with the number of indicies
resulting in that key as the value. If it was already inserted, added to the
answer and then added to the num of indicies. Long long must be used because
the max case is over 10 million.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n, d;
  cin >> n >> d;
  map<ll, ll> result;
  ll ans = 0;
  for(int i=0;i<n;i++) {
    ll temp;
    cin >> temp;
    if(!result.insert(pair<ll, ll>(temp / d, 1)).second) {
      ans += result[temp / d];
      result[temp / d]++;
    }
  }
  cout << ans << endl;

  return 0;
}
