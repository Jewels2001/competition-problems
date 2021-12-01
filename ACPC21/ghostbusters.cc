#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

#define INF 1000000000
#define sz(x) (int)(x).size()
#define debug(a) cerr << #a << " = " << (a) << endl;

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.first << ", " << x.second << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }

const ll MOD = 1000000007;
// computes all binomial coefficients up to MAX_N.  Read them off the table
// after calling precomp().  O(MAX_N^2)
const int MAX_N = 10;
ll binom[MAX_N+1][MAX_N+1];
void precomp()
{
  for (int n = 0; n <= MAX_N; n++) {
    binom[n][0] = binom[n][n] = 1;
    for (int k = 1; k < n; k++) {
      binom[n][k] = binom[n-1][k] + binom[n-1][k-1];
    }
  }
}

// computes single binomial coefficient C(n, k)   O(k)
ll binomfunc(ll n, ll k)
{
  if (k == 0 || k == n) return 1;
  k = min(k, n - k);
  ll ans = 1;
  for (ll i = 1; i <= k; i++) {
    ans = (ans * ((n - k + i) % MOD) % MOD);
    //ans /= i * pow(i);
    ans %= MOD;
  }
  return ans;
}



// ll factorial(ll n) {
//   ll temp = 1;
//   for(ll i=2; i<=n; i++) {
//     temp = temp * i % MOD;
//   }
//   cout << "temp: " << temp <<  "temp mod: " << temp % MOD << endl;
//   return temp % MOD;
// }


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, m;
    cin >> n >> m;

    ll ans = 0;
    if(n == m) {
      ans = 1;
    }
    else if(n < m) {
        // ans = (factorial(m)) / ((factorial(n) * (factorial(m-n)))%MOD);
        ans = binomfunc(m, n);
    }
    else {
      // ans = (n-m)+1;
        ans = binomfunc(n-1, m-1);
    }
    ans = ans % MOD;
    cout << ans << endl;
    return 0;
}
