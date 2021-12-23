#include <bits/stdc++.h>
using namespace std;


int main() {
  vector<string> data;
  int ans = 0;

  //end-of-file input on windows is ctrl-z
  string signal;
  string output;
  while(getline(cin, signal, '|')) {
    getline(cin, output);
    // stringstream ss(signal);
    stringstream ss1(output);
    cout << "output: " << output << endl;

    //count the number of 2,3,4,7 long strings for part one
    string zero, one, two, three,four,five,six,seven,eight,nine;
    for(int i=0; i<10;i++) {
      string temp;
      ss >> temp;
      if(temp.length() == 2) {
        one = temp;
      } else if(temp.length() == 3) {
        seven = temp;
      } else if(temp.length() == 4) {
        four = temp;
      } else if(temp.length() == 7) {
        eight = temp;
      }
      data.push_back(temp);
    }
    for(int j=0; j<4;j++) {
      string t;
      while(ss1 >> t) {
        cout << "t:" << t << endl;
        if(t.length() == 2) {
          ans++;
        } else if(t.length() == 3) {
          ans++;
        } else if(t.length() == 4) {
          ans++;
        } else if(t.length() == 7) {
          ans++;
        }
      }
    }
   }
   cout << ans << endl;
   //part 2:
   //find smallest string's length
   //mark those characters for a given #
   //the letter in 7 (3chars) and not 1 (2chars) is top or aaaa
   //

  return 0;
}
