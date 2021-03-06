#include <bits/stdc++.h>
using namespace std;

// UnionFind class -- based on Howard Cheng's C code for UnionFind
// Modified to use C++ by Rex Forsyth, Oct 22, 2003
//
// Constuctor -- builds a UnionFind object of size n and initializes it
// find -- return index of x in the UnionFind
// merge -- updates relationship between x and y in the UnionFind

class UnionFind {
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


// Determines the point(s) of intersection if a circle and a circle
//
// Author: Darcy Best
// Date  : October 1, 2010
// Source: http://local.wasp.uwa.edu.au/~pbourke/geometry/2circle/
//
// Note: A circle of radius 0 must be considered independently.
// See comments in the implementation.


#define SQR(X) ((X) * (X))

// How close to call equal
const double EPS = 1e-4;

bool dEqual(double x,double y){
  return fabs(x-y) < EPS;
}

struct Point{
  double x,y;
  bool operator<(const Point& a) const{
    if(dEqual(x,a.x))
      return y < a.y;
    return x < a.x;
  }
};
struct Circle{
  double r,x,y;
};

// Input:
//  Two circles to intersect
//
// Output:
//  Number of points of intersection points
//  If 1 (or 2), then ans1 (and ans2) contain those points.
//  If 3, then there are infinitely many. (They're the same circle)
int intersect_circle_circle(Circle c1,Circle c2,Point& ans1,Point& ans2){

  // If we have two singular points
  if(fabs(c1.r) < EPS && fabs(c2.r) < EPS){
    if(dEqual(c1.x,c2.x) && dEqual(c1.y,c2.y)){
      ans1.x = c1.x;
      ans1.y = c1.y;
      // Here, you need to know what the intersection of two exact points is:
      //  "return 1;" - If the points intersect at only 1 point
      //  "return 3;" - If the circles are the same
      // Note that both are true -- It all depends on the problem
      return 1;
    } else {
      return 0;
    }
  }

  double d = hypot(c1.x-c2.x,c1.y-c2.y);

  // Check if the circles are exactly the same.
  if(dEqual(c1.x,c2.x) && dEqual(c1.y,c2.y) && dEqual(c1.r,c2.r))
    return 3;

  // The circles are disjoint
  if(d > c1.r + c2.r + EPS)
    return 0;

  // One circle is contained inside the other -- No intersection
  if(d < abs(c1.r-c2.r) - EPS)
    return 0;

  double a = (SQR(c1.r) - SQR(c2.r) + SQR(d)) / (2*d);
  double h = sqrt(abs(SQR(c1.r) - SQR(a)));

  Point P;
  P.x = c1.x + a / d * (c2.x - c1.x);
  P.y = c1.y + a / d * (c2.y - c1.y);

  ans1.x = P.x + h / d * (c2.y - c1.y);
  ans1.y = P.y - h / d * (c2.x - c1.x);

  if(fabs(h) < EPS)
    return 1;

  ans2.x = P.x - h / d * (c2.y - c1.y);
  ans2.y = P.y + h / d * (c2.x - c1.x);

  return 2;
}

int main() {
  int cases;
  while(cin >> cases && cases != -1) {
    UnionFind yay(cases);
    vector<Circle> rings (cases);
    for(int i=0; i<cases;i++) {
      cin >> rings[i].x >> rings[i].y >> rings[i].r;
    }
    for(int i=0;i<cases;i++) {
      Circle current = rings[i];
      for(int j=0;j<cases;j++) {
        Circle check = rings[j];
        Point a, b;
        if(intersect_circle_circle(current, check, a, b)) {
          bool what = yay.merge(i, j);
        }
      }
    }
    int ans = 1;
    for(int i=0; i<cases;i++) {
      int temp = 1;
      for(int j=i+1;j<cases;j++) {
        if(yay.find(i) == yay.find(j)) {
          temp++;
        }
      }
      ans = max(ans, temp);
    }

    //input
    //first merge intersections
    //union find

    cout << "The largest component contains " << ans
        << (ans == 1 ? " ring." : " rings.") << endl;

  }
  return 0;
}
