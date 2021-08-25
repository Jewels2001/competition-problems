#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

int main(){
  vector<string> cpsc2620;
  vector<string> cpsc2610;
  vector<string> math2000;
  vector<string> common;
  string name;

  cout << "enter cpsc2620: " <<endl;
  for(int n=0;n<33;n++){
    getline(cin, name);
    name.erase(remove(name.begin(), name.end(), ' '), name.end());
    cpsc2620.push_back(name);
  }
  /*
  cout << "enter math2000: " << endl;
  for(int a=0;a<94;a++){
    getline(cin, name);
    name.erase(remove(name.begin(), name.end(), ' '), name.end());
    math2000.push_back(name);
  }
  */
  cout << "enter cpsc2610: " << endl;
  for(int b=0;b<42;b++){
    getline(cin, name);
    name.erase(remove(name.begin(), name.end(), ' '), name.end());
    cpsc2610.push_back(name);
  }

  for(int c=0;c<33;c++){
    string first = cpsc2620[c];
    for(int d=0;d<42;d++){
      if(first == cpsc2610[d]){
        common.push_back(first);
        cout << "In both 2620 and 2610: " << first << endl;
      }
    }
  }
  /*
  for(int e=0;e<35;e++){
    string temp = common[e];
    for(int f=0;f<40;f++){
      if(temp == cpsc2610[f]){
        cout << "They are also in cpsc2610: " << temp << endl;
      }
    }
  }
  */

  int size1 = common.size();
  cout << "The common people are: " << endl;
  for(int i=0;i<size1;i++){
    cout << common[i] << " ";
  }
  return 0;
}
