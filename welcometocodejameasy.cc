#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;
const string CODEJAM = "welcome to code jam";
const int len = CODEJAM.length();

bool substring(string s1, int index) {
    int m = s1.length();
    int currentIndex = index;
    string compare;
    for(int i=index; i<m;i++){
      // if(currentIndex >= len){
      //   return true;
      // }
      if(s1[i] == CODEJAM[currentIndex]){
        currentIndex++;
        compare+= s1[i];
      }
      if(compare == CODEJAM){
        return true;
      }
    //cout << "loopnum:" << i << " test compare: " << compare << endl;
    }

    return false;
}

int main() {
  int cases;
  cin >> cases;
  string temp;
  getline(cin, temp);
  for(int i=1; i<cases+1;i++) {
    string complete;
    int ans = 0;
    getline(cin, complete);
    int current = 0;
    while(current < len){
      if(substring(complete, current)){
        ans++;
        cout << "case" << i << " currentchar: " << current << " ans " << ans << endl;
      }
      current++;
      cout << "case" << i << " currentchar: " << current << " ans " << ans << endl;
    }
    cout<< "Case #" << i << ": ";
    if(ans < 1000){
      cout << 0;
    }
    if(ans < 100){
      cout << 0;
    }
    if(ans < 10){
      cout << 0;
    }
    cout << ans << endl;
  }
  return 0;
}
