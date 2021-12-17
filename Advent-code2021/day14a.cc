#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

map<string, char> insertions;
string lastPolymer;

void findNew(string polymer, int times, int current) {
  string newPolymer = "";
  if(current == times) {
    lastPolymer = polymer;
    return;
  }
  for(int i=0; i<polymer.length()-1; i++) {
    newPolymer += polymer[i];
    char add;
    string key = "";
    if(polymer[i+1] != '.') {
      key += polymer[i];
      key += polymer[i+1];
      add = insertions[key];
      // cout << "add: " << add << "second: " << insertions[key] << endl;
      newPolymer += add;
    }
    else {
      newPolymer += '.';
      cout << "poly: " << polymer << "new: " << newPolymer << endl;
    }
  }
  current++;
  findNew(newPolymer, times, current);
}

int main() {
  string a;

  // vector<int> data;
  int ans = 0;

  string polymer;
  cin >> polymer;
  polymer.append(".");
  getline(cin, a);
  while(getline(cin, a)) {
    string p;
    char c, temp;
    stringstream ss(a);
    ss >> p >> temp >> temp >> c;
    insertions.insert(make_pair(p,c));
  }

  int times = 40;
  int current = 0;
  findNew(polymer, times, current);

  map<char, int> letters;

  for(int i=0; i<lastPolymer.length();i++) {
    if(letters.find(lastPolymer[i]) != letters.end()) {
      letters[lastPolymer[i]]++;
    }
    else {
      letters.insert(make_pair(lastPolymer[i],1));
    }
  }

  int most = 0;
  int least = INF;
  for(auto pair : letters) {
    cout << pair.first << " " << pair.second << endl;
    if (pair.second > most) {
      most = pair.second;
    }
    else if (pair.second < least) {
      least = pair.second;
    }
  }

  cout << "most: " << most << "least: " << least << endl;
  cout << "most - least: " << most - least << endl;



  // for(auto pair : insertions) {
  //   cout << pair.first << " " << pair.second << endl;
  // }

  cout << " "
   << endl;

  return 0;
}
