#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

// UnionFind class -- based on Howard Cheng's C code for UnionFind
// Modified to use C++ by Rex Forsyth, Oct 22, 2003
//
// Constuctor -- builds a UnionFind object of size n and initializes it
// find -- return index of x in the UnionFind
// merge -- updates relationship between x and y in the UnionFind


class UnionFind
{
      struct UF { int p; int rank; };

   public:
      UnionFind(int n) {          // constructor
	 howMany = n;
	 uf = new UF[howMany];
	 for (int i = 0; i < howMany; i++) {
	    uf[i].p = i;
	    uf[i].rank = 0;
	 }
      }

      ~UnionFind() {
         delete[] uf;
      }

      int find(int x) { return find(uf,x); }        // for client use

      bool merge(int x, int y) {
	 int res1, res2;
	 res1 = find(uf, x);
	 res2 = find(uf, y);
	 if (res1 != res2) {
	    if (uf[res1].rank > uf[res2].rank) {
	       uf[res2].p = res1;
	    }
	    else {
	       uf[res1].p = res2;
	       if (uf[res1].rank == uf[res2].rank) {
		  uf[res2].rank++;
	       }
	    }
	    return true;
	 }
	 return false;
      }

   private:
      int howMany;
      UF* uf;

      int find(UF uf[], int x) {     // recursive funcion for internal use
	 if (uf[x].p != x) {
	    uf[x].p = find(uf, uf[x].p);
	 }
	 return uf[x].p;
      }
};

ll binom(int n, int k)
{
  if (k == 0 || k == n) return 1;
  k = min(k, n - k);
  ll ans = 1;
  for (ll i = 1; i <= k; i++) {
    ans *= (n - k + i);
    ans /= i;
  }
  return ans;
}


int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> rails(m);
  UnionFind uf(n);
  for(int i=0; i<m; i++) {
    cin >> rails[i].first >> rails[i].second;
    uf.merge(rails[i].first-1, rails[i].second-1);
  }

  ll total = binom(n, 2);
  ll ans = 0;
  map<int, ll> M;
  for(int i=0; i<n; i++) {
    M[uf.find(i)]++;
  }
  for(auto &p:M) {
    if(p.second == 1) {
      continue;
    }
    ans += binom(p.second, 2);
  }
  double yay = (double)ans/total;
  cout << fixed << setprecision(10) << yay << endl;

  return 0;
}
