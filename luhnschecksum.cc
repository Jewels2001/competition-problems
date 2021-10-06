#include <bits/stdc++.h>
using namespace std;

int main() {
  int cases;
  cin >> cases;
  for(int i=0; i<cases;i++) {
    string x;
    cin >> x;
    reverse(x.begin(), x.end());
    int sum = 0;
    for(int j=1; j<x.length()+1;j++){
      int temp = x[j-1] - '0';
      if(!(j%2)){
        temp *= 2;
        while(temp > 9){
          temp= temp%10 + temp/10;
        }
      }
      sum += temp;
    }
    sum %= 10;
    if(sum == 0){
      cout << "PASS" << endl;
    }
    else {
      cout << "FAIL" << endl;
    }

  }
  return 0;
}
