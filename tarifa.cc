#include <bits/stdc++.h>
using namespace std;

int main(){
  int x, n;
  cin >> x >> n;
  int ans =x;
  for(int i=0;i<n;i++) {
    int temp;
    cin >> temp;
    ans = ans - temp;
    ans = ans + x;
  }
  cout << ans;

  return 0;
}
