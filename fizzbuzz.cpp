#include <iostream>
#include <string>

using namespace std;

int main() {
  int x;
  string f = "fizz";
  string b = "buzz";

  for(int i=1; i<101; i++) {
    if(i%15 == 0) {
      cout << f << b << endl;
    }
    else if(i%3 == 0) {
      cout << f << endl;
    }
    else if(i%5 == 0) {
      cout << b << endl;
    }
    else{
      cout << i << endl;
    }
  }
  return 0;
}
