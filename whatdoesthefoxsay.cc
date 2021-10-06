#include <bits/stdc++.h>
using namespace std;

int main() {
  int cases;
  cin >> cases;
  string temp;
  getline(cin, temp);
  for(int i=0; i<cases;i++) {
    string line, animals, word;
    vector<string> sounds;
    getline(cin, line);
    while(getline(cin,animals)){
      string sound;
      stringstream ss(animals);
      if(animals != "what does the fox say?"){
        int count = 0;
        while(ss>>sound){
          if(count != 2){
            count++;
          }
          else {
            sounds.push_back(sound);
          }
        }
      }
      else{
        break;
      }
    }

    istringstream iss(line);
    while(iss>>word){
      std::vector<string>::iterator it;
      it = find(sounds.begin(), sounds.end(), word);
      if (it != sounds.end()){
        continue;
      }
      else{
        cout << word << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
