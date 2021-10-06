#include <bits/stdc++.h>
using namespace std;

int main() {
  string line;
  while(getline(cin, line)){
    bool perf = true;
    bool golomb = true;
    stringstream ss(line);
    int a;
    vector<int> ruler;
    int hi = 0;
    while(ss >> a){
      ruler.push_back(a);
      if(a >= hi){
        hi = a;
      }
    }
    set<int> ans;
    set<int>::iterator it;
    for(int i=0;i<ruler.size();i++) {
      for(int j=0; j<ruler.size(); j++){
        if(j==i){
          continue;
        }
        if(ruler[j]-ruler[i] >= 0){
          if((find(ans.begin(),ans.end(), ruler[j]-ruler[i]) == ans.end())) {
              ans.insert(ruler[j]-ruler[i]);
            }
          else{
            golomb = false;
          }
        }
      }
    }
    vector<int> missing;
    for(int x=1;x<hi;x++){
      if(!(find(ans.begin(),ans.end(),x)==ans.end())){
        continue;
      }
      else{
        perf = false;
        missing.push_back(x);
      }
    }
    if(perf && golomb){
      cout << "perfect" << endl;
    }
    else if(golomb){
      cout << "missing ";
      for(int x=0;x<missing.size();x++){
        cout << missing[x] << " ";
      }
      cout << endl;
    }
    else {
      cout << "not a ruler" << endl;
    }
    ruler.clear();
  }
  return 0;
}
