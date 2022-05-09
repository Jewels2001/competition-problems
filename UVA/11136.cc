/*
By: Julie Wojtiw-Quo
Used a multiset because, as it is typically implemented as a binary tree, it
sorted/ordered the values AND allowed access to both the end and beginning
(associative and allocator-aware). Long longs were necessary as the total cost
could be (10^6 - 0) * 5000 since one day can be as high as 10^6 and clients get
paid every day of the contest.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n; // up to 5000
  while(cin >> n && n != 0) {
    multiset<ll> bills;
    ll cost = 0;
    for(int i=0; i<n; i++) {
      int a;
      cin >> a; //up to 10^5 or 100000
      while(a--) {
        int temp;
        cin >> temp;
        bills.insert(temp);
      }
      multiset<ll>::iterator low = bills.begin();
      multiset<ll>::iterator hi = --bills.end();
      cost += *hi - *low;
      bills.erase(bills.begin());
      bills.erase(--bills.end());
    }
    cout << cost << endl;
  }
  return 0;
}
