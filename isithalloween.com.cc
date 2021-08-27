#include <bits/stdc++.h>
using namespace std;

int main(){
  string day;
  int n;
  cin >> day >> n;
  bool ans = false;
  if(((day == "OCT") && (n==31)) || ((day == "DEC") && (n == 25)))
    ans = true;

  cout << (ans ? "yup" : "nope");
  return 0;
}
