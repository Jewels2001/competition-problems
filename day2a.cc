#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void passcode(int&, int&, char&, vector<char>&, int&, int&);

int main(){
  int min, max, ans;
  int current =0;
  int invalid = 0;
  int valid = 0;
  int size = 0;
  char temp, key;
  vector<char> pass;

  passcode(min, max, key, pass, valid, size);
  while(true){
    if(min == 0){
      ans = valid - invalid;
      cout << "The number of invalid are: " << invalid << ". The number of valid are: " << valid << ". The answer is: " << ans << endl;
      return 0;
    }
    min -= 1;
    max -= 1;

      //Checks
      cout << "The first is " << min << " and the second is " << max << " and the key is " << key << endl;
      cout << "The pass is: ";
      for(int n=0; n<size; n++){
        char a = pass[n];
        cout << a;
      }
      cout << "." << endl;
      //Checks

      for(int i=0; i<size; i++){
        if(i==min){
          if(pass[i] == key){
            current++;
          }
        }
        if(i==max){
          if(pass[i]==key){
            current++;
          }
        }
      }
      if(current != 1)
        invalid++;
      cout << "There were " << current << " of " << key << endl;
      current = 0;
      pass.erase(pass.begin(), pass.end());
      ans = valid - invalid;
      cout << "The number of invalid are: " << invalid << ". The number of valid are: " << valid << ". The answer is: " << ans << endl;

    passcode(min, max, key, pass, valid, size);
  }
  return 0;
}

void passcode(int& min, int& max, char& key, vector<char>& pass, int& valid, int& size){
  char letter, temp;
  cin >> min >> temp >> max >> key >> temp;
  cin.get(temp);
  while(letter != ' '){
    cin.get(letter);
    pass.push_back(letter);
    cout << letter << endl;
    if(cin.peek() == '\n'){
      break;
    }
  }
  size = pass.size();
  valid++;
  cout << "number of valid: " << valid << endl;
}
