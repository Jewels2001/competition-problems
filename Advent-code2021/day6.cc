#include <bits/stdc++.h>
using namespace std;

int DAYS = 80;

int main() {
  int a[9] = {0};
  int ans=0;

  int b;
  char t;
  while (cin >> b >> t) {
    a[b]++;
  }
  cout << "initial" << endl;
  for(int k=0; k<9;k++) {
    cout << a[k] << ",";
  }

  for(int i=0; i<DAYS;i++) {
    int temp[9];
    //change timers
    for(int j=8; j>=0;j--) {

      if(j != 0) {
        temp[j-1]=a[j];
      }
      else {
        //move 0's to reproduce
        temp[8] = a[0];
        temp[6] += a[0];
      }
    }
    cout << "After day " << i << " ";
    for(int k=0; k<9;k++) {
      cout << a[k] << ",";
    }
    cout << endl;
    //move into old array
    copy(temp, temp+9, a);
  }

  for(int i=0; i<9; i++) {
    ans+= a[i];
  }
  cout << ans << endl;
  return 0;
}
