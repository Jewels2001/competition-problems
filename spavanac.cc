#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, m;
  cin >> h >> m;
  m -= 45;
  if(m<0) {
    h--;
    m+=60;
  }
  if(h<0){
    h+=24;
  }
  //cout:
  cout << h << " "<< m;

  return 0;
}
