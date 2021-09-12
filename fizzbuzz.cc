#include <iostream>
#include <string>

using namespace std;

int main() {
  int x, y, n;
  cin >> x >> y >> n;
  string f = "Fizz";
  string b = "Buzz";

  for(int i=1;i<n+1;i++) {
    if((i%x == 0) && (i%y == 0)) {
      cout << f << b << endl;
    }
    else if(i%x == 0) {
      cout << f << endl;
    }
    else if(i%y == 0) {
      cout << b << endl;
    }
    else{
      cout << i << endl;
    }
  }
  return 0;
}
