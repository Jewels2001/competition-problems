#include <bits/stdc++.h>
using namespace std;

int main() {
  stringstream ss;
  vector<int> days;

  string calls;
  cin >> calls;
  calls.push_back(',');
  ss << calls;

  int a;
  char b;
  while (ss >> a >> b) {
    days.push_back(a);
  }

  int size = days.size();
  for(int i=0;i<80;i++) {
    cout << i << endl;
    sort(begin(days), end(days));
    size = days.size();
    while(days[0] == 0) {
      days[0] = 6;
      days.push_back(8);
      sort(begin(days), end(days));
    }
    for(int j=0; j<size;j++){
      days[j] -= 1;
    }
  }
  cout << days.size() << endl;
}
