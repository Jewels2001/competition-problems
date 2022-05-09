/*
By: Julie Wojtiw-Quo
Created a set to hold distinct city names. Outputted the size of the set.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int cases;
  cin >> cases;
  while(cases--) {
    int trips;
    set<string> places;
    cin >> trips;
    for(int j=0; j<trips; j++) {
      string city;
      cin >> city;
      places.insert(city);
    }
    cout << places.size() << endl;
  }
  return 0;
}
