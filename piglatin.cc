#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
  return (c == 'a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y');
}

int main() {
  string line, word;
  while(getline(cin, line)) {
    string ans;
    stringstream ss(line);
    while(ss>>word) {
      if(isVowel(word[0])){
        word += "yay";
      }
      else {
        string temp;
        int i=0;
        while(!isVowel(word[i]) && i<word.length()){
          temp+= word[i];
          i++;
        }
        word = word.substr(i) + temp + "ay";
      }
      ans += word + " ";
    }
    cout << ans;
  }
  return 0;
}
