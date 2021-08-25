#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  int max = n/k;
  /*if(n == 0){
    cout << 0;
    return 0;
  }*/
  int tempmax = max;
  vector <int> deadlines;
  for(int i=0; i<n; i++){
    int temp;
    cin >> temp;
    deadlines.push_back(temp);
  }

  sort(deadlines.begin(), deadlines.end());

  int current = deadlines[0];
  int count = 1;
  int tempcount;
  for(int j=1; j<n; j++){
    if(current == deadlines[j]){
      count++;
      tempcount++;
      if(n%2 != 0){
        if(count > max){
        if(n == k){
          tempmax--;
        }
        else if(count >= n/2){
          continue;
        }
        if(deadlines[j] != deadlines[j+1]){
          continue;
        }
      }
    }
      if(count > max){
        tempmax--;
      }
    }
    else{
      count = 1;
      current = deadlines[j];
    }
    if(tempmax <= 0){
      cout << 0;
      return 0;
    }
    if(count > tempcount){
      tempcount = count;
    }
  }
  cout << tempmax;

  return 0;
}
