#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;

int main() {
  ll n,e;
  ll ans=0;
  cin >> n >> e;
   // (x << n)  or (1 << e)
  string first = to_string(1 << e);
  for(int j=0;j<=n;j++){
    string temp = to_string(j);
    ans += (temp.find(first) != string::npos);
  }
  cout << ans << endl;
  return 0;
}
