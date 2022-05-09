/*
By: Julie Wojtiw-Quo
Kruskal's algorithm (minimum spanning tree) - it sorts edges smallest weight to
largest, then for each edge i it checks if they are already connected using
union find. If not already connected, while edges are <= r, build roads,
else build railroads. The number of states will always be the number of cities
minus the number of roads.
*/

#include <bits/stdc++.h>
using namespace std;
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

struct Edge {
  int i1;
  int i2;
  double dist;
};

vector<pair<int, int>> c(1000);
// vector<vector<int>> g(1000);
vector<Edge> weights;

int main() {
  int t;
  cin >> t;
  int cases = 1;
  while(t--) {
    int n, r;
    cin >> n >> r;
    c.clear();
    c.resize(n);
    weights.clear();
    //weights = sqrt[(xi - xj)^2 + (yi - yj)^2]
    for(int i=0; i<n; i++) {
      int x, y;
      cin >> x >> y;
      c[i] = make_pair(x, y);
    }
    for(int i=0; i<n; i++) {
      int x1 = c[i].first;
      int y1 = c[i].second;
      // x1, y1
      for(int j=i+1; j<n;j++) {
        int x2 = c[j].first;
        int y2 = c[j].second;
        //compute distance to all other points
        //put in (squared) distances vector/ graph
        //r will need to be squared later to compare
        // dists will need to be sqrted to add for output
        Edge temp;
        temp.i1 = i;
        temp.i2 = j;
        temp.dist = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
        weights.push_back(temp);
      }
    }
    //run kruskals
    int roads = 0;
    double rdist = 0;
    double rrdist = 0;
    //step 1 sort weights smallest to largest
    sort(begin(weights), end(weights),
          [](const Edge& a, const Edge& b) {return a.dist <= b.dist;});
    UnionFind uf(n);
    double r2 = r*r;
    //step 2 pick smallest
    for(auto &i : weights) {
      //if already connected/cycle, do not use
      if(uf.find(i.i1) == uf.find(i.i2)) {
        continue;
      }
      uf.merge(i.i1, i.i2);
      if(i.dist <= r2) {
        rdist += sqrt(i.dist);
        roads++;
      } else {
        rrdist += sqrt(i.dist);
      }
    }

    cout << fixed << setprecision(0) << "Case #" << cases++ << ": " << (n-roads)
         << " " << rdist << " " << rrdist << endl;
  }
  return 0;
}
