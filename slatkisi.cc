#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000


int main() {
  string price;
  int k;
  cin >> price >> k;

  int pos = price.length() - k;

  int tens = k*10;
  cout << "MOD: " << stoi(price) % tens << endl;

  for(int i=pos-1; i<price.length(); i++) {
    if(i == pos) {
      if((price[i]) >= '5') {
        price[i] = price[i] + 1;
      } else {
        price[i] = '0';
      }
    }
    else {
      price[i] = '0';
    }
  }
  cout << price << endl;






  //
  // for(int i=price.length()-1; i>=pos; i--) {
  //   cout << "SPOT: " << price[i] << endl;
  //   cout << "COMPARE: " << (price[i]  > '5') << endl;
  //
  //   if((price[i]) > '4') {
  //     price[i] = '0';
  //     cout << "OLD: " << price[i-1] << endl;
  //     price[i-1] = price[i-1] + 1;
  //     cout << "NEW: " << price[i-1] << endl;
  //
  //   }
  // }
  // cout << price << endl;

  return 0;
}
