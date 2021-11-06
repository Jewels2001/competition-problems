#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;
const double PI = acos(-1.0);

int main() {
  //cout:
  cout << " ";
  //cin:
  cin >> "";

  //round up
  (A+(B-1)) /B

  return 0;
}


//with cases
#include <bits/stdc++.h>
using namespace std;

//long long
typedef long long ll;
const double PI = acos(-1.0);

int main() {
  int cases;
  cin >> cases;
  for(int i=0; i<cases;i++) {
    //cout:
    cout << " ";
    //cin:
    cin >> "";

    //round up
    (A+(B-1)) /B
    cout<< "Case #" << cases << ": " << ans << endl;
  }
  return 0;
}

// Ways to change to binary
bitset<32> bs (number);

__builtin_popcount(number)

  //string concatenationto int
  string a;
  string r = a;
  stoi(a+r);

  //string word parsing
  int main() {
    string line, word;
    while(getline(cin, line)) {
      istringstream iss(line);
      while(iss>>word) {
        // code goes here
      }
    }
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

  //for checking diff in cmd line
  prog < input | diff - output


  //random minSwaps function
  int minSwaps(vector<int> arr, int n) {
    vector<pair<int, int>> arrPos(n);
      for(int i=0; i<n;i++){
      arrPos[i].first = arr[i];
      arrPos[i].second = i;
    }
    sort(arrPos.begin(), arrPos.end());
    vector<bool> visited(n, false);
    int ans = 0;
    for(int i=0;i<n;i++){
      if (visited[i] || arrPos[i].second == i)
        continue;
      int cycle_size = 0;
      int j = i;
      while(!visited[j]){
        visited[j] = 1;
        j = arrPos[j].second;
        cycle_size++;
      }
      if(cycle_size > 0){
        ans += (cycle_size - 1);
      }
    }
    return ans;
  }
