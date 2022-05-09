#include <bits/stdc++.h>
using namespace std;

int main(){
  int trips;
  int cases;
  string city;
  cin >> cases;
  if(cases == 0){
    cout << "0";
  }
  for(int i=0; i<cases;i++) {
    set<string> places;
    cin >> trips;
    if(trips == 0){
      cout << "0";
      return 0;
    }
    for(int j=0; j<trips; j++){
      cin >> city;
      places.insert(city);
    }
    cout << places.size() << endl;
  }

  return 0;
}
