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

bool check(const vector<int>& stamps, const int& q, int p1, int p2, int p1a, int p2a) {
  if(q < p1a && q < p2a) {
    return false;
  }
  else if(q == p1a || q == p2a || q == p1a+p2a) {
    return true;
  }

  int next = p1a;
  if(p1<stamps.size()) {
    ++p1;
    next += stamps[p1];
    if(q == next || q == next+p2a) {
      return true;
    }
  }
  next = p2a;
  if(p2 > 0) {
    --p2;
    next += stamps[p2];
    if(q == next || q == next+p1a) {
      return true;
    }
  }
  p1a += stamps[p1];
  p2a += stamps[p2];
  check(stamps, q, p1, p2, p1a, p2a);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> stamps (n);
  ll total = 0;
  for(int i=0;i<n;i++) {
    cin >> stamps[i];
    total += stamps[i];
  }
  for(int i=0;i<m;i++) {
    int q;
    cin >> q;
    if(q > total) {
      cout << "No" << endl;
      continue;
    }
    // else if(q < stamps[0] || q < stamps[n]) {
    //   cout << "No" << endl;
    //   continue;
    // }
    else {
      int p1 = 0;
      int p2 = n-1;
      cout << ((check(stamps, q, p1, p2, stamps[0], stamps[n-1])) ? "Yes" : "No") << endl;
      continue;
    }
  }
}
