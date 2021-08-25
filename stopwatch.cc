#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  if (n%2) {
    cout << "still running";
    return 0;
  }
  bool on = false;
  int time = 0;
  int lasttime =0;

  for(int i=0;i<n;i++) {
    int temp;
    cin >> temp;
    on = !on;
    if(!on) {
      time += temp - lasttime;
    }
    lasttime = temp;
  }

  cout << time;
  return 0;
}
