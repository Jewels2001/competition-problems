#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;
const double PI = acos(-1.0);

int gcd(int a, int b) {
  int r;
  while (b) {
    r = a % b;
    a = b;
    b= r;
  }
  return a;
}

void reduce(int &a, int &b){
  int g = gcd(abs(a), b);
  a /= g;
  b /= g;
}

void convert(int& fTop, int& fBot) {
  int tempTop, tempBot;
  tempTop = fTop - (32*fBot);
  tempTop = tempTop*5;
  tempBot = fBot*9;

  fTop = tempTop;
  fBot = tempBot;
}


int main() {
  int a, b;
  char temp;
  cin >> a >> temp >> b;
  convert(a, b);
  reduce(a, b);
  cout << a << temp << b << endl;

  return 0;
}
