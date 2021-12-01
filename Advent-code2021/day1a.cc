#include <bits/stdc++.h>
using namespace std;

int main() {
  int one;
  vector<int> data;
  int ans = 0;

  do{
    cin >> one;
    data.push_back(one);
  } while (one);

  int a = data.size();
  int part1 = data[0];
  int part2 = data[1];
  int part3 = data[2];
  int lastSum = part1 + part2 + part3;
  for(int i=1; i<a; i++) {
    int part1 = data[i];
    int part2 = data[i+1];
    int part3 = data[i+2];
    int sum = part1 + part2 + part3;
    if(sum > lastSum) {
      ans++;
    }
    lastSum = sum;
  }
  cout << ans << endl;
  return 0;
}
