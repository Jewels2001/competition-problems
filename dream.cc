#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


void check(int,int,int,int, int&);

int main(){
  int a,b,c;
  int n;
  int x;

  cin >> a >> b >> c >> n;
  if(n < 3){
    cout << "NO";
    return 0;
  }
  if((a < 1) || (b < 1) || (c < 1)){
    cout << "NO";
    return 0;
  }
  if((a + b +c) >= n){
    cout << "YES";
    return 0;
  }
  else{
    cout << "NO";
    return 0;
  }
}
