/*
By: Julie Wojtiw-Quo
Stored all the keywords and excuses. Used a separate function to convert the
excuses to lowercase and any punctuation to whitespace. Utilized exact string
comparison for checking whether a string between whitespace or white-space
converted punctuation was a keyword. (if a keyword was broken up by punctuation
it would not be the same) Stored number of keywords for each excuse and outputted
the excuses that matched the max.
*/
#include <bits/stdc++.h>
using namespace std;

void lowercase(string& excuse) {
  for(int i=0; i<excuse.length();i++) {
    excuse[i] = tolower(excuse[i]);
    if(!(isalpha(excuse[i]))) {
      excuse[i] = ' ';
    }
  }
}


int main() {
  int k, e;
  int num = 1;
  while(cin >> k >> e) {
    vector<string> keywords(k);
    for(int i=0;i<k;i++) {
      string temp;
      cin >> temp;
      keywords[i] = temp;
    }
    string newline;
    getline(cin, newline);
    int best = 0;
    vector<string> estrings (e);
    vector<int> elengths (e);
    for(int j=0;j<e;j++) {
      string excuse;
      getline(cin, excuse);
      estrings[j] = excuse;

      lowercase(excuse);

      istringstream ss(excuse);
      string temp;
      int current = 0;
      while(ss >> temp) {
        for(int x=0;x<k;x++) {
          if(temp == keywords[x]) {
            current++;
          }
        }
      }
      elengths[j] = current;
      best = max(best, current);
    }


    cout << "Excuse Set #" << num << endl;
    for(int i=0; i<e;i++) {
      if(elengths[i] == best) {
        cout << estrings[i] << endl;
      }
    }
    cout << endl;
    ++num;
  }

  return 0;
}
