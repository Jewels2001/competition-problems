/*
By: Julie Wojtiw-Quo
Uses a struct to store the name and class of a person. Class is split by the '-'
then reversed for easier sorting. Used a system of 1 for upper, 0 for middle
and -1 for lower in the sort function. Given that "all further classes are the
same as the middle level", added "middle" designation to any class that had a
sequence of less than 10 for easier bounds checking.
*/
#include <bits/stdc++.h>
using namespace std;

struct Person {
  string name;
  vector<int> c;
};

//sorting function for pairs of Person struct
bool f(const Person& a, const Person& b) {
  for (int i=0;i<10;i++) {
    if(a.c[i] > b.c[i]) {
      return true;
    }
    else if(a.c[i] < b.c[i]) {
      return false;
    }
  }
  return a.name <= b.name;
}


int main() {
  int cases;
  cin >> cases;
  while(cases--) {
    int n;
    cin >> n;
    vector<Person> ppl;
    for(int i=0; i<n;i++) {
      Person temp;
      string t;
      string cl;
      cin >> temp.name >> cl >> t;
      temp.name.pop_back();
      //replaces - with whitespace for stringstream separation
      replace(begin(cl),end(cl),'-',' ');

      istringstream ss(cl);
      //denotes middle as 0, upper as 1 and lower as -1. could have used a map
      while(ss >> t) {
        int a = 0;
        if(t == "upper") {
          a = 1;
        }
        else if (t == "lower") {
          a = -1;
        }
        temp.c.push_back(a);
      }
      reverse(begin(temp.c), end(temp.c));
      //since middle level is same, adds middle designation for easier bounds
      for(int j=temp.c.size();j<10;j++) {
        temp.c.push_back(0);
      }
      ppl.push_back(temp);
    }
    //sorts inputted people
    sort(begin(ppl), end(ppl), f);

    for(int i=0;i<n;i++) {
      cout << ppl[i].name << endl;
    }
    cout << "==============================" << endl;
  }
  return 0;
}
