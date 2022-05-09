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


int main() {
  int n;
  cin >> n;

  vector<string> guilds(n);
  //set<string>

  map<string, int> test;
  int count = 0;
  for(int i=0; i<n;i++) {
    istringstream ss;
    string a, b;
    cin >> ss;
    guilds[i] = ss;
    ss >> a >> b;

    if(test.insert(pair<string, int>(a, count)).second) {
      ++count;
    }
    if(test.insert(pair<string, int>(b, count)).second) {
      ++count;
    }
    // test.insert(pair<string, int>(b, ++count));
    // if(find(begin(guilds), end(guilds), a) == end(guilds)) {
    //     guilds.push_back(a);
    // }
    // if(find(begin(guilds), end(guilds), a) == end(guilds)) {
    //     guilds.push_back(b);
    // }
    cout << test[a] << " b: " << test[b] << endl;
  }
  int s = test.size();
  cout << "size: " << s << endl;
  UnionFind uf(s);
  for(int i=0; i<n;i++) {
    stringstream temp = guilds[i];
    string a, b;
    ss >> a >> b;
  }
    uf.merge(test[a],test[b]);
    cout << "hi" << endl;


  return 0;
}
