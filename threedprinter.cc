#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000


// from geometry3D.cc
const double PI = acos(-1.0), EPS = 1e-8;

struct Vector {
  double x, y, z;
  Vector(double xx = 0, double yy = 0, double zz = 0) : x(xx), y(yy), z(zz) { }
  Vector(const Vector &p1, const Vector &p2)
    : x(p2.x - p1.x), y(p2.y - p1.y), z(p2.z - p1.z) { }
  Vector(const Vector &p1, const Vector &p2, double t)
    : x(p1.x + t*p2.x), y(p1.y + t*p2.y), z(p1.z + t*p2.z) { }
  double norm() const { return sqrt(x*x + y*y + z*z); }
  bool operator==(const Vector&p) const{
    return abs(x - p.x) < EPS && abs(y - p.y) < EPS && abs(z - p.z) < EPS;
  }
};

double dot(Vector p1, Vector p2) { return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z; }

Vector cross(Vector p1, Vector p2) {
  return Vector(p1.y*p2.z-p2.y*p1.z, p2.x*p1.z-p1.x*p2.z, p1.x*p2.y-p2.x*p1.y);
}

// Compute the volume of a convex polyhedron (input is an array of triangular faces)
typedef tuple<Vector,Vector,Vector> tvvv;
double volume_polyhedron(vector<tvvv>& p){
  Vector c,p0,p1,p2; double v, volume = 0;
  for(int i=0;i<p.size();i++)
    c = c + get<0>(p[i]) + get<1>(p[i]) + get<2>(p[i]);
  c = 1/(3.0*p.size())*c;
  for(int i=0;i<p.size();i++){
    tie(p0,p1,p2) = p[i], v = dot(p0,cross(p1,p2)) / 6;
    if(dot(cross(p2-p1,p0-p1),c-p0) > 0) volume -= v;
    else volume += v;
  }
  return volume;
}


int main() {
  int n;
  cin >> n;
  // for every polyhedron
  for(int i=0; i<n; i++) {
    vector<tvvv> polyhedrons;
    int f;
    cin >> f;
    // for every face
    for(int j=0;j<f; j++) {
      // for every vertex
      int v;
      cin >> v;
      // make every face a triangle (not every face is a triangle)
    }

    tvvv temp;

  }
  tvvv
  //cout:
  cout << " ";
  //cin:
  cin >> "";
  //debug cerr

  //round up
  (A+(B-1)) /B

  return 0;
}
