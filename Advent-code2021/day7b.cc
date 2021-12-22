#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int calc(int pos, int num) {
  int temp = num;

  int dist = abs(num - pos);
  temp = ((dist * (dist-1))/2) + dist;

  return temp;
}

int main() {
  int ans = 0;
  vector<int> crabs;
  int a;
  char t;
  //add , onto end of input
  while(cin >> a >> t) {
    crabs.push_back(a);
  }
  sort(crabs.begin(), crabs.end());

  int best = INF;
  for(int i=0; i<crabs.back(); i++) {
    int pos = i;
    int fuel = 0;
    for(int j=0; j<crabs.size();j++) {
      fuel += calc(pos, crabs[j]);
    }
    if(fuel <= best) {
      best = fuel;
    }
  }
  cout << "ans:" << best << endl;
  return 0;
}
