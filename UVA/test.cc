
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector <string> a {"apples", "dog", "banana"};
  for(int i=0; i<a.size(); i++) {
    cout << a[i].length() << endl;
  }
}
