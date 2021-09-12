#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> s;


  for(int i=0; i<n;i++) {
    int temp;
    cin >>temp;
    s.push_back(temp);
  }


  int ans = s[0];
  int count =n+1;
  int d=1;

  while(count){
    cout << ans << " ";
    s.erase(s.begin());
    int calc =0;
    for(int j=1;j<n;j++) {
      calc += s[j]*d;
    }
    ans+=calc;

    d++;
    count--;
  }

  cout << " ";


  return 0;
}
