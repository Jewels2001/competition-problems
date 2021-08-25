#include <bits/stdc++.h>
using namespace std;

int main(){
  int cases;
  cin >> cases;
  for(int i=0; i<cases;i++){
    int r;
    int p;
    int d;
    cin >> r >> p >> d;



  }
  //cout:
  cout << " ";
  //cin:
  cin >> "";

  //round up
  (A+(B-1)) /B

  return 0;
}

  //string concatenationto int
  string a;
  string r = a;
  stoi(a+r);

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

  //for checking diff in cmd line
  prog < input | diff - output
