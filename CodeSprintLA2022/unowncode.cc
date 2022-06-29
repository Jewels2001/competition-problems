#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);

  for(ll i=0; i<n; i++) {
    cin >> a[i];
  }
  cout << "hi" << endl;
  //for every number
    //for each in array
  ll ans = -1;
  ll i, j;
  for(j=2; j<10000; j++) {
    for(i=0; i<a.size(); i++) {
      ll len = to_string(a[i]).length();
      cout << "LEN:" << len << endl;
      ll p = 10;
      for(int k=0; k<len; k++) {
        ll temp = p;
        p *= temp;
      }
      //ll p = pow(10, len);
      ll x = a[i];
      for(int k=0; k<j; k++) {
        ll temp = x;
        x *= temp;
      }
      cout << x << " " << p << " " << x % p << endl;
      if(x % p == a[i]) {
        cout << "J:" << j << endl;
        ans = j;
        continue;
      } else {
        break;
      }
    }
    if(i == a.size()) {
      break;
    }
  }
  cout << "ANS:" << endl;
  cout << ans << endl;



  return 0;
}
