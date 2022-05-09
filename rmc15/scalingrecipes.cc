/*
By: Julie Wojtiw-Quo
Used a struct to store the information. Checked for the main ingredient and
stored its information in order to compare everything else to it. Reset the
vector with .clear() at the end of every case.
*/
#include <bits/stdc++.h>
using namespace std;

//struct to store information about each ingredient
struct Ingredient{
  string name;
  double weight;
  double per;
  double scaled;
  bool main = false;
};


int main() {
  int t;
  cin >> t;
  int case_num =1;
  for(int i=1; i<t+1; i++) {
    cout << "Recipe # " << case_num++ << endl;
    int r;
    double p;
    double d;
    cin >> r >> p >> d;

    //scaling formula
    double scaling = d/p;
    double mainScale = 0;

    vector<Ingredient> food;

    for(int j=0; j<r;j++) {
      Ingredient temp;
      cin >> temp.name >> temp.weight >> temp.per;
      if (temp.per == 100.0) {
        temp.main = true;
        temp.scaled = (temp.weight*scaling);
        mainScale = temp.scaled/100;
      }
      food.push_back(temp);
    }
    for(auto a:food) {
      if(!a.main) {
        a.scaled = (a.per*mainScale);
      }
      cout << fixed << setprecision(1) << a.name << " " << a.scaled << endl;
    }
    food.clear();
    cout << setfill('-') << setw(40) << "" << endl;
  }
  return 0;
}
