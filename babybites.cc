//B
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

int main() {
  int n;
  cin >> n;
  vector<string> nums(n);
  for(int i=0; i<n;i++) {
    cin >> nums[i];
  }
  int count = 1;
  for(auto i : nums) {
    if(isdigit(i[0])) {
      if(stoi(i) != count) {
        cout << "something is fishy";
        return 0;
      }
    }
    count++;
  }
  cout << "makes sense";
  return 0;
}
