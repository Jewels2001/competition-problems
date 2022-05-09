/*
By: Julie Wojtiw-Quo
Taking the absolute value of the subtraction results in a correct answer no
matter what order the input is in. Int data type cannot be used because the
largest int is 2^32-1, while the largest input is 2^32.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a,b;
  while(cin >> a >> b) {
    cout << abs(a - b) << endl;
  }
  return 0;
}
