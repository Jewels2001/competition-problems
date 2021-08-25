#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans;
  ans = n%2;
  if(ans == 1)
    cout << "Alice";
  else
    cout << "Bob";

  return 0;
}
