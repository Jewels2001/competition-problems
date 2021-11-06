#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;
const double PI = acos(-1.0);

int main() {
  int l, h, k;
  cin >> l >> h >> k;
  vector<vector<stack<char>>> laptop;
  laptop.resize(h);
  for(int i=0; i< h;i++) {
    laptop[i].resize(l);
    for(int j=0; j<l;j++) {
      laptop[i][j].emplace('_');
    }
  }


  char temp = 'a';
  for(int a=0;a<k;a++){
    int length, height, x, y;
    cin >> length >> height >> x >> y;
    for(int i=y; i<min(height+y, h);i++){
      for(int j=x;j<min(length+x,l);j++){
        laptop[i][j].emplace(temp);
      }
    }
    temp += 1;
  }

  for(int i=0; i< h; i++) {
    for(int j=0; j<l; j++) {
      cout << laptop[i][j].top();
    }
    cout << endl;
  }

  return 0;
}
