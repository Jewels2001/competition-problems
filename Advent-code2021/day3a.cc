//with cases
#include <bits/stdc++.h>
using namespace std;

// int convert(bitset n) {
//   int dec = 0, i = 0, rem;
//
//   while (n!=0) {
//     rem = n % 10;
//     n /= 10;
//     dec += rem * pow(2, i);
//     ++i;
//   }
//
//   return dec;
// }

const string most = "110010111011";
const string least = "001101000100";

vector<string> oxy;
vector<string> co2;

void checkDigits(vector<string>& woo) {
  int s=woo.size();
  for(int k=0; k<s; k++){
    int sLen = woo[k].length();
    string temp = woo[k];
    for(int j=0; j<sLen; j++){
      if(temp[j] == most[j]) {
        oxy.push_back(temp);
      }
      else if(temp[j] == least[j]) {
        co2.push_back(temp)
      }
    }
  }
}

void removeStrings(vector<string>& boo) {
  int s
}




int main() {
  vector<string> data;
  vector<int> nums (12, 0);
  int ans = 0;

  string aaa;
  int one = 0;
  int two = 0;
  int three = 0;
  int four = 0;
  int five = 0;
  int six = 0;
  int seven = 0;
  int eight = 0;
  int nine = 0;
  int ten = 0;
  int ele = 0;
  int twelve = 0;

  while(cin >> aaa) {
    data.push_back(aaa);
  }

  int a = data.size();
  int b = data[0].length();

  vector<string> oxy;
  vector<string> co2;

  for(int i=0; i<a; i++) {
    string temp = data[i];
    for(int j=0; j<b; j++) {


      }


      if(temp[j] == '1') {
        nums[j]++;
      }
    }
  }
  string apple = "";
  string inverseApple = "";

  for(int j=0;j<nums.size();j++) {
    if (nums[j] > a/2) {
      apple += "1";
      inverseApple += "0";
    }
    else {
      apple += "0";
      inverseApple += "1";
    }
  }






  bitset<12> bits(apple);
  bitset<12> bits1(inverseApple);
  cout << "apple: " << bits.to_ulong() << " inverse: " << bits1.to_ulong() << endl;
  cout << bits.to_ulong() * bits1.to_ulong() << endl;
  return 0;
}
