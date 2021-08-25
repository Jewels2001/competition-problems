#include <iostream>
using namespace std;

int main(){
  int n;
  int count = 0;
  cin >> n;
  int t[n];
  for(int i=0; i<n; i++){
    cin >> t[i];
    if(t[i] < 0){
      count++;
    }
  }
  cout << count;
  return 0;
}
