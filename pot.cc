#include <bits/stdc++.h>
using namespace std;

//unfinished?
int main(){
  int n;
  cin >> n;
  int ans=0;
  for(int i=0;i<n;i++) {
    int temp;
    int power;
    cin >> temp;
    power = temp %10;
    temp /= 10;
    for(int j=0;j<power;j++){
      temp *= temp;
    }
    ans += temp;
  }
  cout << ans;
  return 0;
}
