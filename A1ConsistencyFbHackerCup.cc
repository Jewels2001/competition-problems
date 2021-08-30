#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
  return (c == 'A' || c=='E' || c == 'I' || c=='O' || c=='U');
}

int main() {
  int t;
  cin >> t;
  int case_num =1;
  for(int i=1; i<t+1; i++) {
    string s;
    cin >> s;
    int ans =INT_MAX;

    for(int j='A'; j<='Z'; j++) {
      //loop through letters
      //comapre each letter's changes to the minimum number of changes
      int count = 0;
      for(auto a:s) {
        if(a == j) {
          continue;
        }
        if (is_vowel(j) ^ is_vowel(a)){
          count++;
        }
        else {
          count += 2;
        }
      }
      ans = min(count, ans);
    }

    cout << "Case #" << case_num++ << ": " << ans << endl;
  }

  return 0;
}
