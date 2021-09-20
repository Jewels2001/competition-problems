#include <bits/stdc++.h>
using namespace std;

int calc(string x, int size) {
  int ans = 1;
  for(int i=0; i<size;i++) {
    int temp = (x[i] - '0');
    if(temp != 0){
      ans *= temp;
    }
  }
  return ans;
}


int main() {
  string x;
  cin >> x;

  int size = x.length();
  while(size > 1) {
    int y = calc(x, size);
    x = to_string(y);
    size = x.length();
  }

  cout << x;

  return 0;
}
