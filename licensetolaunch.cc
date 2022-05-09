#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000


int main() {
  int n;
  cin >> n;
  int min = INF;
  int day = 0;
  for(int i=0; i<n; i++) {
    int temp;
    cin >> temp;
    if(temp < min) {
      min = temp;
      day = i;
    }
  }
  //cout:
  cout << day;

  return 0;
}
