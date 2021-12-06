#include <bits/stdc++.h>
using namespace std;


int i;
int func(int& k) {
 k += 5;
 i -= -4;
 cout << "k: " << k << " global i: " << i << endl << endl;
 return 2 * k + i - 1;
}

int main() {
  int j = 20;
  int sum1, sum2, sum3;
  i = 10;

  cout << "i: " << i << " j: " << j << endl;
  sum1 = (i/2) + func(i);
  cout << "after sum1 i: " << i << " j: " << j << endl;
  cout << "SUM1: " << sum1 << endl << endl ;
  sum2 = func(i) + func(j) + i;
  cout << "after sum2 i: " << i << " j: " << j << endl << endl;
  cout << "SUM2: " << sum2 << endl << endl ;
  sum3 = 2 * func(i);
  cout << "after sum3 i: " << i << " j: " << j << endl << endl;
  cout << "SUM3: " << sum3 << endl << endl ;

  return 0;
}
