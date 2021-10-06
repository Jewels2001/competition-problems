#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isSubsetSum(pair<string,int> p, ll n, ll s){
  if(s == 0)
    return true;
  if(n == 0)
    return false;
  if(p)


}

int main() {
  ll n, s;
  cin >> n >> s;
  pair<string, int> participants;
  for(ll i=0;i<n;i++){
    string name;
    ll temp;
    cin >> name >> temp;
    participants = make_pair(name, temp);
  }
  bool ans = isSubsetSum(participants, n, s);
  //cout:
  cout << " ";
  //cin:
  cin >> "";

  //round up
  (A+(B-1)) /B

  return 0;
}
