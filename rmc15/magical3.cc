/*
By: Julie Wojtiw-Quo
A math theory problem - given n is less than 2^31, we try up to INT_MAX
(2147483648 = 2^31 is max). Special cases if n is 3 answer is 4, if n is less
than 3 then there is no base. When n is greater than 3, for numbers that are
evenly divisible we find the minimum of the number and divisible factors of the
number. We only have to try all numbers up to sqrt(n).
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll n;
  while(cin >> n && n != 0) {
    if(n == 3) {
      cout << 4 << endl;
      continue;
    }
    else if(n < 3) {
      cout << "No such base" << endl;
      continue;
    }
    ll ans = INT_MAX;
    n -= 3;
    // n-3 because easy check if n is divisible by i (math theory if a-b is
    //divisible by x, then a is equivalent to b mod x)
    // if sieve, up to sqrt(n), or i*i < sqrt(n)^2
    for(ll i=1; i*i<=n; i++) {
      if(!(n % i)) {
        if(i >= 4) {
          ans = min(ans, i);
        }
        //accounts for multiples/divisible numbers
        if(n/i >= 4) {
          ans = min(ans, n/i);
        }
      }
    }
    if(ans < INT_MAX) {
      cout << ans << endl;
    }
    else {
      cout << "No such base" << endl;
    }
  }

  return 0;
}
