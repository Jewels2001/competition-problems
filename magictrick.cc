#include <bits/stdc++.h>
using namespace std;

int main(){
  string input;
  cin >> input;
  int s = input.length();

  bool ans = true;
  set<char> apples;
  for(int i=0;i<s;i++) {
    if(apples.find(input[i]) == apples.end())
      apples.insert(input[i]);
    else {
      ans = false;
      break;
    }
   }

  cout << ans;
  return 0;
}
