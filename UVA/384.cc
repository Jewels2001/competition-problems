/*
By: Julie Wojtiw-Quo
A string processing input parsing problem with a function to check slimp
constraints and a function to check slump constraints. We go through the string,
looking for a slimp and a slump, and if there are extra characters (the slimp +
the slump do not make up the entire string) then it is not a Slurpy.
*/
#include <bits/stdc++.h>
using namespace std;

bool slumpCheck(string s) {
  //check property 1
  if(s[0] != 'D' && s[0] != 'E') {
    return false;
  }
  //check property 2
  int i=1;
  while(s[i] == 'F') {
    i++;
  }
  if(i == 1) {
    return false;
  }
  //check property 3
  if(s[i] == 'G' || slumpCheck(s.substr(i))) {
    return true;
  }
  //is not a slump
  return false;
}

bool slimpCheck(string s) {
  //check property 1
  if(s.length() == 0 && s[0] != 'A') {
    return false;
  }

  //check property 2
  if(s == "AH") return true;
  //check property 3
  if(s.length() >= 3 && s[1] == 'B' && s[s.length()-1] == 'C' && slimpCheck(s.substr(2, s.length()-3))) {
    return true;
  }
  else if(s.length() >= 2 && s[s.length()-1] == 'C' && slumpCheck(s.substr(1, s.length()-2))) {
    return true;
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  cout << "SLURPYS OUTPUT" << endl;
  while(t--) {
    string s;
    cin >> s;
    bool ans = false;
    int i=0, j=0;
    string str = s.substr(0, i);
    while(i<=s.length()) {
      if(slimpCheck(str)) {
        break;
      }
      i++;
      str = s.substr(0, i);
    }
    if(slimpCheck(str)) {
      j = i;
      i = 0;
      while(i < s.length()) {
        if(slumpCheck(s.substr(j, i))) break;
        i++;
      }
    }
    ((j+i != s.length()) ? ans = false : ans = true);

    cout << (ans ? "YES" : "NO") << endl;
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}
