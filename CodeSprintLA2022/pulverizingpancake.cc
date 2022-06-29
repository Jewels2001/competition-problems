//with cases
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

string a = "";

vector<int> arr;

bool boundsCheck(int i) {
  if(i >= 0 && i <= a.length()-1) {
    return true;
  }
  return false;
}

bool checkString() {
  for(int i=0; i<a.length(); i++) {
    cout << a[i] << endl;
    if(a[i] == '1') {
      return false;
    }
  }
  return true;
}

int pancake(int i, int value) {
  cout << "I: " << i << " V: " << value << endl;
  cout << a << endl;
  //barrel down i:
  a[i] = '0';
  if(boundsCheck(i-1) && boundsCheck(i-2)) {
    a[i-1] = '0';
    a[i-2] = '1';
  }
  if(boundsCheck(i+1) && boundsCheck(i+2)) {
    a[i+1] = '0';
    a[i+2] = '1';
  }
  if(checkString()) {
    return value + 1;
  }
  return pancake(i+1, value+1);

}

int main() {
  int n, m;
  cin >> n >> m;
  cin >> a;
  cout << a << endl;
  int ans = INT_MAX;

  arr.clear();
  arr.resize(n, 0);
  for(int i=0; i<n; i++) {
    ans = min(ans, pancake(i, 0));
  }
  cout << "ANS:" << ans << endl;


  return 0;
}
