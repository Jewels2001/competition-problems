#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

//determine number of bits in binary representation
//log2(n) + 1 (3 bits to represent 5)
//111
//int maxN = (1 << numBits) - 1; 


int main() {
  double c;
  cin >> c;
  double a = ceil(log2(c)); //max 30

  double nums = pow(2, a); //max 2^30
  double denom = nums - 1;
  int restarts = nums - c;
  cout << "nums: " << nums << " res: " << restarts << endl;

  bitset<30> bs (c-1);
  string test = bs.to_string();
  cout << test << endl;

  bitset<30> bs2 (denom);
  string test2 = bs2.to_string();
  cout << bs2 << endl;

  map<int, int> flips;
  while(test2 != test) {

  }

  double ans = (c/nums * a);
  cout << ans << endl;

  //double erounds = nums / c;

  return 0;
}
