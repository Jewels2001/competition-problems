#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

// 0 = c, 1 = m, 2 = c or m

int main() {
  map<string, int> table1;
  table1.insert(pair<string, int>("number of", 0));
  table1.insert(pair<string, int>("amount of", 1));
  table1.insert(pair<string, int>("most", 2));
  table1.insert(pair<string, int>("fewest", 0));
  table1.insert(pair<string, int>("least", 1));
  table1.insert(pair<string, int>("more", 2));
  table1.insert(pair<string, int>("fewer", 0));
  table1.insert(pair<string, int>("less", 1));
  table1.insert(pair<string, int>("many", 0));
  table1.insert(pair<string, int>("much", 1));
  table1.insert(pair<string, int>("few", 0));
  table1.insert(pair<string, int>("little", 1));

  int n, p;
  cin >> n >> p;
  map<string, int> nouns;

  for(int i=0; i<n; i++) {
    pair<string, int> temp;
    string a;
    cin >> temp.first >> a;
    if(a == "c") {
      temp.second = 0;
    } else if(a == "m") {
      temp.second = 1;
    } else {
      temp.second = 2;
    }
    nouns.insert(temp);
  }
  string temp;
  getline(cin, temp);
  for(int i=0; i<p; i++) {
    string phrase;
    getline(cin, phrase);
    istringstream ss(phrase);
    string temp;
    ss >> temp;
    if(table1.find(temp) == table1.end()) {
      string a;
      ss >> a;
      temp += " " + a;
    }
    int k = table1[temp];
    string newNoun;
    ss >> newNoun;
    int k1 = nouns[newNoun];

    if(k == 2) {
      cout << "Correct!" << endl;
    }
    else {
      cout << (k == k1 ? "Correct!" : "Not on my watch!") << endl;
    }
  }

  return 0;
}
