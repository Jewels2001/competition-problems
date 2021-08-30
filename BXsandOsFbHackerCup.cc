#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  int case_num =1;
  for(int i=1; i<t+1; i++) {
    int ans = 0;
    int numOfX = 0;

    int n=0;
    cin >> n;
    vector<vector<int>> a (n,(vector<int> (n)));
    priority_queue<pair<int,int>> q;

    for(int i=0; i<n;i++) {
      int x = 0;
      char temp;
      cin >> temp;
      for(int j=0; j<n;j++) {
        
      }
    }


    cout << "Case #" << case_num++ << ": " << numOfX << " "<< ans << endl;
  }
  return 0;
}
