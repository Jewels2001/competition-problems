#include <bits/stdc++.h>
using namespace std;

int main() {
  int cases;
  cin >> cases;
  for(int i=0; i<cases;i++) {
    int godzilla, mechaGodzilla;
    cin >> godzilla >> mechaGodzilla;
    priority_queue<int> pq1;
    priority_queue<int> pq2;
    for(int j=0; j<godzilla;j++){
      int temp;
      cin >> temp;
      pq1.push(-temp);
    }
    for(int j=0; j<mechaGodzilla;j++){
      int temp;
      cin >> temp;
      pq2.push(-temp);
    }

    while(!pq1.empty() && !pq2.empty()){
      if(pq1.top() > pq2.top()){
        pq1.pop();
      }
      else if(pq2.top() > pq1.top()){
        pq2.pop();
      }
      else {
        pq2.pop();
      }
    }

    if(pq1.empty()){
      cout << "MechaGodzilla" << endl;
    }
    else if(pq2.empty()){
      cout << "Godzilla" << endl;
    }
    else {
      cout << "uncertain" << endl;
    }
  }
  return 0;
}
