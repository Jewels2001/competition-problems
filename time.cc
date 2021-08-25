#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main(){
  int n, h1, m1, h2, m2, alpha;
  string ew;
  cin << n << h1 << ew << m1 << h2 << ew << m2 << alpha;
  for(int i=0;i<n;i++){

    int f, f1, g, g1, t1, t2, x;
    f = (h1*360)/24;
    f1 = (h2*360)/24;
    g = (m1*360)/60;
    g1 = (m2*360)/60;
    t1 = f + f1;
    t2 = g + g1;
    x = t2 - t1;
    int answer =






  }
  return 0;
}
