//with cases
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double PI = acos(-1.0);
#define INF 1000000000

int main() {
  int t;
  cin >> t;
  while(t--) {
    double totalTime = 0.00;
    double currTime = 0.00;
    int n;
    cin >> n;
    priority_queue<int> pq;
    //vector<int> people(n);
    // bubble sort until it is sorted?
    // shortest job first


    for(int i=0; i<n; i++) {
        int wood;
        int time = 0;
        cin >> wood;
        for(int j=0; j<wood; j++) {
            int temp;
            cin >> temp;
            time += temp;         
        }
        pq.push(-time);
    }
    // size of wood = time
    // num pieces 
    while(!pq.empty()) {
        double next = -pq.top(); pq.pop();
        currTime += next;
        totalTime += currTime;
    }
    cout << fixed << setprecision(6) << totalTime / double(n) << endl;

  }
  return 0;
}