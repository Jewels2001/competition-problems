#include <bits/stdc++.h>
using namespace std;

int main(){
  int a[3];

  cin >> a[0] >> a[1] >> a[2];
  sort(a,a+3);

  char b;
  //if-elses == bad and gross
  for(int i=0; i<3; i++) {
    cin >> b;
    switch (b) {
      case 'A':
        cout << a[0] << " ";
        break;
      case 'B':
        cout << a[1] << " ";
        break;
      case 'C':
        cout << a[2] << " ";
        break;
    }
  }

  return 0;
}
