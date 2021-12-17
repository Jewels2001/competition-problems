#include <bits/stdc++.h>
using namespace std;

const string most = "110010111011";
const string least = "001101000100";

vector<string> oxy;
vector<string> co2;

char mostCommon(vector<string> noo, int pos, bool m) {
  int a = noo.size();
  // int b = noo[0].length();
  //vector<int> nums (12, 0);
  int nums = 0;
  for(int i=0; i<a; i++) {
    if(noo[i][pos] == '1') {
      nums++;
    }
  }
  char apple;
  char inverseApple;
  if(pos == 7 && m == false) {
    for(int i=0; i<a; i++) {
      cout << "yay: ";
      cout << noo[i][pos] << endl;
    }
    cout << "nums: " << nums << "size: " << a << endl;
  }


  if(nums >= ceil(a/2.0)) {
    apple = '1';
    inverseApple = '0';
  }
  else {
    apple = '0';
    inverseApple = '1';
  }

  if(m) {
    return apple;
  }
  else {
    return inverseApple;
  }
}

void checkFirstDigits(vector<string> woo) {
  int s = woo.size();
  for(int k=0; k<s; k++) {
    if(woo[k][0] == most[0]) {
      oxy.push_back(woo[k]);
    }
    else if(woo[k][0] == least[0]) {
      co2.push_back(woo[k]);
    }
  }
}

void removeStrings(vector<string>& boo, int pos, bool oxy) {

  // if(pos == 7 && oxy == false) {
  //   cout << "co2" << endl;
  //   for(int i=0; i<co2.size(); i++) {
  //     cout << co2[i] << endl;
  //   }
  //   cout << mostCommon(co2, 7, false) << endl;
  // }

  int num = pos + 1;
  int len = boo[0].length();
  char oops, opps;
  if(pos == len) {
    cout << "pos: " << pos << endl;
    return;
  }
  if(oxy) {
    oops = mostCommon(boo, pos, true);
  }
  else {
    opps = mostCommon(boo, pos, false);
  }

  for(int k=0; k<boo.size(); k++) {
    string temp = boo[k];
    if(oxy) {
      if(boo[k][pos] != oops) {
        if(boo.size() == 1) {
          return;
        }
        else {
          boo.erase(boo.begin()+k);
          k--;
        }
      }
    }
    else {
      if(boo[k][pos] != opps) {
        if(boo.size() == 1) {
          return;
        }
        else {
          boo.erase(boo.begin()+k);
          k--;
        }
      }
    }
  }
  removeStrings(boo, num, oxy);
}


int main() {
  vector<string> data;
  vector<int> nums (12, 0);
  int ans = 0;

  string aaa;
  //input
  while(cin >> aaa) {
    data.push_back(aaa);
  }

  int a = data.size();
  int b = data[0].length();

  // vector<string> oxy;
  // vector<string> co2;
  //check all for first digit and save them into a vector
    //put rest into another vector
  checkFirstDigits(data);

  //use vector1, check all for second digit
  //remove those that aren't matching
  int p = 1;
  removeStrings(oxy, p, true);
  removeStrings(co2, p, false);
  //do for rest of digits

  //answer
  string o;
  string c;
  cout << "oxy:" << endl;
  for(int i=0; i<oxy.size(); i++) {
    o = oxy[i];
    cout << oxy[i] << endl;
  }
  cout << "co2" << endl;
  for(int i=0; i<co2.size(); i++) {
    c = co2[i];
    cout << co2[i] << endl;
  }

  bitset<12> bits(o);
  bitset<12> bits1(c);
  cout << "oxy: " << bits.to_ulong() << " co2: " << bits1.to_ulong() << endl;
  cout << bits.to_ulong() * bits1.to_ulong() << endl;
  //
  // string apple = "";
  // string inverseApple = "";
  //
  // // for(int j=0;j<nums.size();j++) {
  // //   if (nums[j] > a/2) {
  // //     apple += "1";
  // //     inverseApple += "0";
  // //   }
  // //   else {
  // //     apple += "0";
  // //     inverseApple += "1";
  // //   }
  // // }
  //
  //
  // bitset<12> bits(apple);
  // bitset<12> bits1(inverseApple);
  // cout << "apple: " << bits.to_ulong() << " inverse: " << bits1.to_ulong() << endl;
  // cout << bits.to_ulong() * bits1.to_ulong() << endl;
  return 0;
}
