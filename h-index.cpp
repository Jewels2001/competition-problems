#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> papers(n);
  for(int i=0; i<n; i++){
    cin >> c[i];
  }

  sort(papers.rbegin(), papers.rend());

  int ans = 0;
  for(int =0; i<papers.size(); i++){
    if (c[i] >= i+1)  ans = i+1;
  }
  cout << ans << endl;

  return 0;
}
