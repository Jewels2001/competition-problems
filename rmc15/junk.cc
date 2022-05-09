/*
By: Julie Wojtiw-Quo
A calculation problem involving the intersection of two lines in 3d-space. Uses
quadratic formula to calculate the different cases:
Cases:
- different, never collide
- different, collide in past (never)
- different, collide.
- same path, one behind is faster and collides
Must account for radius colliding earlier
*/

#include <bits/stdc++.h>
using namespace std;

int calcLine(double& root) {
  int sx,sy,sz,sjx,sjy,sjz;
  int svx, svy, svz, sjvx, sjvy, sjvz;
  int sr, sjr;
  cin >> sx >> sy >> sz >> sr >> svx >> svy >> svz;
  cin >> sjx >> sjy >> sjz >> sjr >> sjvx >> sjvy >> sjvz;
  // line for ship is (sx, sy, sz) + time(svx, svy, svz)
  // <x, y, z> = <sx + t(svx), sy + t(svy), sz + t(svz)>
  int x = sx - sjx, y = sy - sjy, z = sz - sjz;
  int vx = svx - sjvx, vy = svy - sjvy, vz = svz - sjvz;
  //a^2 + b^2 + c^2 <= r^2
  //double x = (sx - sjx)

  // vx^2 + vy^2 + vz^2 + 2(x*vx + y*vy + z*vz) + (x^2 + y^2 + z^2 - (sr+sjr)^2)
  /*from x^2 + y^2 + z^2 < r^2
    to at^2 + bt +c >= 0
    (xt + yt + zt)^2
  */
  int a = vx*vx + vy*vy + vz*vz;
  int b = 2*(x*vx + y*vy + z*vz);
  int c = x*x + y*y + z*z - (sr+sjr)*(sr+sjr);
  //apply quadratic formula
  int discriminant = b*b - 4*a*c;

  //same path
  if(a == 0 || b == 0) {
    return -1;
  }
  // different, collide in past (never)
  else if(b >= 0 && discriminant < b*b) {
    return -1;
  }
  // different, never collide
  else if(discriminant < 0) {
    return -1;
  }
  // different, collide.
  else {
    root = (-b - sqrt(discriminant)) / (2 * a);
    return 0;
  }
  return 0;
}

int main() {
  int cases;
  cin >> cases;
  while(cases--) {
    double root = 0.0;
    int ans = calcLine(root);
    if(ans == -1) {
      cout << "No collision" << endl;
    } else {
      cout << fixed << setprecision(3) << root << endl;
    }
  }
  return 0;
}
