#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; //exercises
  cin >> t;
  int case_num =1;

  for(int i=0; i<t;i++) {
    int n;
    cin >> n;
    bool x = false;
    int ans = 0;
    bool foundFirst = false;

    //set<char> apples;
    //string full = "";
    for(int s=0;s<n;s++) {
      char temp;
      cin >> temp;
      //full += full + temp;
      //apples.insert(temp);

      if(foundFirst && x){
        if(temp == 'O') {
          ans++;
          x = false;
        }
      }
      else if(foundFirst && !x) {
        if(temp == 'X'){
          x = true;
          ans++;
        }
      }
      if((temp == 'X') || (temp == 'O')) {
        foundFirst = true;
        x = temp == 'X';
      }

    }
    cout << "Case #" << case_num++ << ": " << ans << endl;
  }
  return 0;
}
