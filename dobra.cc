#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = INT_MAX;
  int underscores = 0;
  int l = 0;
  int vowels = 0;
  int consonant = 0;
  int answers = 0;
  vector<string> input;
  for(int i = 0; i<n; i++){
    cin >> input[i];
  }
  for(int i=0; i<n; i++) {
    if(input[i] == "_"){
      underscores++;
      if(vowels == 2) {

      }
    }
    else if(input[i] == "A" || input[i] == "E" || input[i] == "I" || input[i] == "O" || input[i] == "U"){
      vowels++;
    }
    if(input[i] == "L"){
      l++;
    }
    else{
      consonant++;
    }
  }
  cout << answers;

  return 0;
}
