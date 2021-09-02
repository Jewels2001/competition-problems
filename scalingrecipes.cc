#include <bits/stdc++.h>
using namespace std;

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
