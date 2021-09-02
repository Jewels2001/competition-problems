#include <bits/stdc++.h>
using namespace std;

struct Date {
  int year;
  int month;
  int day;
};

Date dateParser() {
  Date d;
  char temp;
  cin >> d.year >> temp >> d.month >> temp >> d.day;
  return d;
}


int main() {
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    string name;
    cin >> name;
    cout << name << " ";

    Date school = dateParser();
    Date birth = dateParser();
    int courses;
    cin >> courses;

    bool eligible = false;
    bool under40 = true;

    if((school.year >= 2010) || (birth.year >= 1991)){
      eligible = true;
    }
    if(courses > 40) {
      under40 = false;
    }

    if (eligible) {
      cout << "eligible" << endl;
    }
    else if(under40) {
      cout << "coach petitions" << endl;
    }
    else {
      cout << "ineligible" << endl;
    }
  }

  return 0;
}
