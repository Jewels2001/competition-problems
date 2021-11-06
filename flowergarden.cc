#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;


int main() {
  //Sieve of Eratosthenes primes computation
  bool primes[20001];
  fill(primes, primes+20001, true);
  primes[1] = false;
  for(int i=2;i*i<20001;i++) {
    if (primes[i]){
      for(int j=i*i;j<20001;j+=i) {
        primes[j] = false;
      }
    }
  }

  int cases;
  cin >> cases;
  for(int i=0; i<cases;i++) {
    int n, d;
    cin >> n >> d;
    d = d*d;
    int ans =0;
    int lastPrime=0;
    //int currentDist =0;
    int x=0;
    int y=0;
    bool done = false;
    for(int j=0;j<n;j++) {
      int x1, y1;
      cin >> x1 >> y1;
      if(done){
        continue;
      }
      int dist = abs(x1-x)*abs(x1-x) + abs(y1-y)*abs(y1-y);//calculating this wrong
      if(dist > d){
        done = true;
        continue;
      }
      else {
        d -= dist;
        x = x1;
        y = y1;
        ans++;
        if(primes[ans]){
          lastPrime = ans;
        }
      }
    }
    // if(primes[ans]){
    //   cout<< ans << endl;
    // }
    //else {
      cout << lastPrime << endl;
    //}
  }
  return 0;
}
