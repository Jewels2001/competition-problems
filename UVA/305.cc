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
  int k = -1;
  while(cin >> k) {
    if(k == 0) {
      break;
    }

    int n = k*2;
    bool ans = false;
    //int n,f,k,kOrder[MAX_N];  f=k,, k=m
    int m=k+1;
    int kOrder[MAX_N];
    while(!ans) {
      killOrder(k,n,m,m,kOrder);
      bool correct = false;
      for(int i=0; i<k;i++) {
        // cout << "k: " << k;
        // cout << " i " << i << " kOrder[i] " << kOrder[i] << endl;
        if(kOrder[i] <= k) {
          //find(begin(baddies),end(baddies),kOrder[i]) == baddies.end()
          correct = false;
          break;
        }
        else {
          correct = true;
        }
      }
      if(correct) {
        ans = true;
      }
      else {
        ++m;
      }
    }
    cout << m << endl;
  }

  return 0;
}
