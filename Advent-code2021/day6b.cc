#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll DAYS = 256;

int main() {
  ll a[9] = {0};
  ll ans=0;

  ll b;
  char t;
  while (cin >> b >> t) {
    a[b]++;
  }

  for(ll i=0; i<DAYS;i++) {
    ll temp[9];
    //change timers
    for(ll j=8; j>=0;j--) {

      if(j != 0) {
        temp[j-1]=a[j];
      }
      else {
        //move 0's to reproduce
        temp[8] = a[0];
        temp[6] += a[0];
      }
    }
    cout << "After day " << i << " ";
    for(ll k=0; k<9;k++) {
      cout << a[k] << ",";
    }
    cout << endl;
    //move into old array
    copy(temp, temp+9, a);
  }

  for(ll i=0; i<9; i++) {
    ans+= a[i];
  }
  cout << ans << endl;
  return 0;
}
