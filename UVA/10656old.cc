/*
By: Julie Wojtiw-Quo
Since all numbers are non-negative, we only have to look out for 0s. Stores all
non-zero numbers in an array and keeps the index, outputting them all if the
index is greater than 0. Otherwise, the input was all 0s and we output 0.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  while(cin >> x, x != 0) {
    if(x == 0) {
      break;
    }
    vector<int> a(x);
    vector<int> maxSum(x);
    int index = 0;
    for(int i=0; i<x; i++) {
      cin >> a[i];
      if(a[i] > 0) {
        maxSum[index++] = a[i];
      }
    }
    if(index == 0) {
      cout << "0";
    }
    else {
      int i=0;
      for(i=0; i< index-1; i++) {
        cout << maxSum[i] << " ";
      }
      cout << maxSum[i];
    }
    cout << endl;
  }

  return 0;
}
