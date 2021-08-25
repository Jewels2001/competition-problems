#include <bits/stdc++.h>
using namespace std;

int main(){
  int n = 0;
  int m = 0;
  cin >> n;
  cin >> m;
  vector<int> sizes;
  vector<int> paints;
  for(int i=0; i< n; i++){
    int temp;
    cin >> temp;
    sizes.push_back(temp);
  }
  for(i=0; i<m; i++) {
      cin >> temp;
      paints.push_back(temp);
  }


  return 0;
}

  //sort
  sort(begin(t), end(t));   //== sort(t.begin(), t.end())DONT USE
  //sort greatest/largest
  sort(begin(t), end(t), cmp); //greater<int>, orcomparison a>b, a<b
  //->reversible containers can be looped backwards
  sort(t.rbegin(), t.rend()); //increasing order backwards

  //uninitialized for loop ex:
  int n, m;
  vector<int> t(n), l(m);
  int t_i = 0. l_i = 0;
  for( ; l_i < m; l_i++){
    for ( ; t_i < n && t[t_i] > l[l_i]; t_i++)
    ;
    if (t_i++ >= n) break;
  }
