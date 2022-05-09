/*
By: Julie Wojtiw-Quo
Created a map to store the foreign words as keys paired with the english words.
Then, for all the words, checked to see if they were in the map.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, string> dict;
  string eng, foreign;
  string line;
  while(getline(cin, line)) {
    if(line.empty()) {
      break;
    }
    istringstream ss(line);
    ss >> eng >> foreign;
    dict.insert(std::pair<string, string>(foreign, eng));
  }


  string key;
  while(cin >> key) {
    if(dict.find(key) != dict.end()) {
      cout << dict.find(key)->second << endl;
    }
    else {
      cout << "eh" << endl;
    }
  }

  return 0;
}
