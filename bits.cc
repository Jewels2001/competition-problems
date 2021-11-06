#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;

int main() {
  int cases;
  cin >> cases;
  for(int i=0; i<cases;i++) {
    int num;
    cin >> num;
    string str = to_string(num);
    int ans = 0;
    //string str2 = s.substr(0,1);
    for(int i=0; i<str.length();i++) {
      int ans2 =0;
      string str2 = str.substr(0, i+1);
      //cout << "substring: " << str.substr(i) << "i: " << i << endl;
      bitset<32> s (stoi(str2));
      ans2 = s.count();
      ans = max(ans, ans2);
    }

    cout<< ans << endl;
  }
  return 0;
}
