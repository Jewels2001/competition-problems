//with cases
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);

int main() {
  int cases = 1;
  int w,l;
  while(cin >> w >> l) {
    if(w == 0 && l == 0) {
      break;
    }
    vector<vector<char>> h(l, vector<char>(w));
    pair<int,int> entrance;
    int direction =0; //0 = right, 1 = up, 2=left, 3=down
    char current = '*';
    for(int i=0;i<l;i++) {
      for(int j=0;j<w;j++){
        char temp;
        cin >> temp;
        h[i][j] = temp;
        if(temp == '*'){
          entrance.first = i;
          entrance.second = j;
        }
      }
    }

    //top
    if(entrance.first == 0){
      direction = 3;
    }
    //bottom
    else if (entrance.first == l-1){
      direction = 1;
    }
    //left
    else if (entrance.second == 0) {
      direction = 0;
    }
    //right
    else if (entrance.second == w-1){
      direction = 2;
    }
    else {
      cout << "error" << endl;
    }

    int i1=entrance.first;
    int j1=entrance.second;
    while(current != 'x') {
      if(direction == 0) {
        j1+=1;
        current=h[i1][j1];
        if(current == '/') {
          direction = 1;
        } else if(current == '\\') {
          direction = 3;
        }
      } else if (direction == 1) {
        i1-=1;
        current=h[i1][j1];
        if(current == '/') {
          direction = 0;
        } else if(current == '\\') {
          direction = 2;
        }
      } else if (direction == 2) {
        j1-=1;
        current = h[i1][j1];
        if(current == '/') {
          direction = 3;
        } else if(current == '\\') {
          direction = 1;
        }
      } else if (direction == 3) {
        i1+=1;
        current = h[i1][j1];
        if(current == '/') {
          direction = 2;
        } else if(current == '\\') {
          direction = 0;
        }
      }
    }
    h[i1][j1] = '&';

    cout << "HOUSE " << cases << endl;
    for(int i=0; i<l;i++){
      for(int j=0;j<w;j++){
        cout << h[i][j];
      }
      cout << endl;
    }
    cases++;
  }
  return 0;
}
