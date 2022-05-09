/*
By: Julie Wojtiw-Quo
Uses two priority queues in order to keep the kth (or ith) element in a
dynamically sorted list. Inserts the values of A only up to the GET and
proceeds to balance the priority queues.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

int main() {
  int k;
  cin >> k;
  while(k--) {
    priority_queue<int> hi;
    priority_queue<int, vector<int>, greater<int>> lo;
    int n, m;
    cin >> m >> n;
    int i = 0;
    int num = 0;
    int p = 0;
    vector<int> a(m);
    //vector<int> u(n);
    for(int j=0; j<m; j++) {
      cin >> a[j];
    }
    for(int j=0; j<n; j++) {
      //cin >> u[j];
      int temp;
      cin >> temp;
      while(temp > p) {
        //put elements into correct pq
        if(hi.empty() && lo.empty()) {
          lo.push(a[p]);
        }
        else if(a[p] >= lo.top()) {
          lo.push(a[p]);
        }
        else {
          hi.push(a[p]);
        }
        p++;
      }
      //p = temp now
      //still need to balance the pqs
      while(hi.size() > i) {
        lo.push(hi.top());
        hi.pop();
      }
      //output current element at i, i++
      //i should be lo.top()
      cout << lo.top() << endl;
      i++;
      int y = lo.top();
      lo.pop();
      hi.push(y);
    }

    if(k > 0) {
      cout << endl;
    }
  }
  return 0;
}
