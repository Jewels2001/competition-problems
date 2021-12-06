#include <bits/stdc++.h>
using namespace std;

int i = 0;

int func(int& k) {
  k += 5;
  i -= -4;
  cout << "k: " << k << " global i: " << i << endl << endl ;
  return (2 * k + i - 1);
}

int main()
{
 int i = 5;
 int j = 15;
 int sum1, sum2, sum3;

 // cout << "left to right: " << endl << endl;
 //
 // cout << "i: " << i << " j: " << j << endl;
 // sum1 = (i/2) + func(i);
 // cout << "after sum1 i: " << i << " j: " << j << endl;
 // cout << "SUM1: " << sum1 << endl << endl ;
 // sum2 = i + j + func(j) * func(j) + func(i);
 // cout << "after sum2 i: " << i << " j: " << j << endl << endl;
 // cout << "SUM2: " << sum2 << endl << endl ;
 // sum3 = func(i) + i + 2 * func(i);
 // cout << "after sum3 i: " << i << " j: " << j << endl << endl;
 // cout << "SUM3: " << sum3 << endl << endl ;

 cout << "right to left: " << endl << endl;

 cout << "i: " << i << " j: " << j << endl;
 sum1 =  func(i) + (i/2);
 cout << "after sum1 i: " << i << " j: " << j << endl;
 cout << "SUM1: " << sum1 << endl << endl ;
 sum2 = func(i) + func(j) * func(j) + j + i;
 cout << "after sum2 i: " << i << " j: " << j << endl << endl;
 cout << "SUM2: " << sum2 << endl << endl ;
 sum3 = func(i) * 2 + i + func(i);
 cout << "after sum3 i: " << i << " j: " << j << endl << endl;
 cout << "SUM3: " << sum3 << endl << endl ;

 return 0;
}
