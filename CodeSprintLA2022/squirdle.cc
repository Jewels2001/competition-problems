#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

string alpha = "11111111111111111111111111";
int arr[5][26];
for(int i=0; i<5; i++) {
  for(int j=0; j<26; j++) {
    arr[i][j] = 1;
  }
}

void wordleing(string& s, int i, int guess) {
  string s2 = "_____";
  if(guess == 2)
    s2 = "pylon";
  else if(guess == 3)
    s2 = "shuck";
  else {
    for(int n=0; n<5; n++) {
      for(int k=0; k<26; k++) {
        if(alpha[k] == '1') {
          s2[n] = 'a' + k;
          break;
        }
      }
    }
  }
  cout << "S2: " << s2 << endl;
    // cout << "bye " << s2 << endl;

  //check
  if(alpha[s2[i] - 'a'] == '1') {
    // cout << "yay" << endl;
    s[i] = s2[i];
  } else {
    
    // cout << "yay" << endl;
    // for(int k=0; k<26; k++) {
    //   if(alpha[k] == '1') {
    //     s[i] = 'a' + k;
    //   }
    // }
  }
}

int main() {
  int guess = 1;

  string s = "?????";

  string response = "";
  cout << char('a' + 0) << endl;

  while(response != "22222") {
    if(guess == 1) {
      s = "irate";
    }
    for(int i=0; i<response.length(); i++) {

      cout << "S: " << s << " " <<  alpha << endl;
      if(response[i] == '2') {
        arr[i][s[i]-'a'] = 2;
        continue;
      }
      if(response[i] == '1') {
        arr[i][s[i]-'a'] = 0;
        cout << "hi" << endl;
        for(int j=0; j<5; j++) {
          if(j == i) {
            continue;
          }
          if(response[j] != '2') {
            s[j] = s[i];
            break;
          }
        }
        wordleing(s, i, guess);
      } else if(response[i] == '0') {
        for(int k=0; k<5; k++) {
          arr[k][s[i]-'a'] = 0;
        }
        // cout << "hi2" << endl;
        alpha[s[i] - 'a'] = '0';
        wordleing(s, i, guess);
      }
    }
    cout << "? " << s;
    cout << '\n';
    cout.flush();
    guess++;
    cin >> response;
    if(response == "22222") {
      return 0;
    }
  }

  return 0;
}
