/*
By: Julie Wojtiw-Quo
Used code from josephus.cc in the code library. Pre-computed the correct possible
m for all input since k < 14 gives a max number of people 13*2 and calculating
the kill order will be O(26^2). Reduced the time complexity of computing the
killOrder by only going up to the number of bad people (k), or half of n.

Initially attempted to compute the kill order during input, but got TLE because
it would be re-computing the order for every input and the problem does not
specify how many numbers will be given for input.
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 27;

void killOrder(int e, int n,int f,int k,int A[]){
  if(n == e) return;
  A[0] = 0;
  killOrder(e, n-1,k,k,A+1);
  for(int i=0;i<n;i++)
    A[i] = (A[i] + (f-1)) % n + 1;
}

int main() {
  int answers[15];
  for(int k=1;k<14;k++) {
    int n = k*2;
    bool ans = false;
    //int n,f,k,kOrder[MAX_N];  f=k,, k=m
    int m=k+1;
    int kOrder[MAX_N];
    while(!ans) {
      killOrder(k,n,m,m,kOrder);
      bool correct = false;
      for(int i=0; i<k;i++) {
        if(kOrder[i] <= k) {
          correct = false;
          break;
        }
        else {
          correct = true;
        }
      }
      if(correct) {
        ans = true;
        answers[k] = m;
      }
      else {
        ++m;
      }
    }
  }

  int kk = -1;
  while(cin >> kk) {
    if(kk == 0) {
      break;
    }

    cout << answers[kk] << endl;
  }

  return 0;
}
