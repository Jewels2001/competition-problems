#include <bits/stdc++.h>
using namespace std;

int main(){
  string ans = "yes";
  long long int ports = 0, wires =0, s=0, l=0;
  //vector<long long int> sockets;
  //vector<long long int> lengths;
  cin >> ports >> wires;
  priority_queue< pair<long long int, long long int>> w;

  vector<long long int> sockets;
  priority_queue<long long int> lengths;
  for(long long int i=0; i<ports;i++){
    cin >> s;
    sockets.push_back(s);
  }
  for(long long int i=0; i<wires;i++){
    cin >> l;
    lengths.push(l);
  }

  //for(long long int i=0; i<n;i++){
  //  w.push_back(make_pair(sockets[i], lengths[i]));
  //}
  sort(sockets.begin(), sockets.end());
  if(ports < wires){
    ans = "no";
    cout << ans;
    return 0;
  }
  while(!lengths.empty()){
    if(lengths.top() <= ( sockets[sockets.size()-1]) - sockets.front()){
      lengths.pop();
    }
    else{
      ans = "no";
      cout << ans;
      return 0;
    }
  }
  cout << ans;
  return 0;
}
