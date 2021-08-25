#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  int max = n/k;
  if(n == 0){
    cout << 0;
    return 0;
  }
  int tempmax = max;
  vector<int> deadlines;
  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    deadlines.push_back(temp);
  }

  sort(deadlines.begin(), deadlines.end());

  vector <int> list;
  int current = deadlines[0];
  int count = 1;

  for(int j = 1; j < n+1; j++){
    while(current == deadlines[j]){
      count++;
      j++;
    }
    current = deadlines[j];
    list.push_back(count);
    count = 1;
  }

  for(int x=0; x<list.size(); x++){
    if((list[x] > max) && (list[x] < k)){
      tempmax--;
    }
    if(tempmax == 0){
      cout << 0;
      return 0;
    }
  }


/*
  int temp = list[0];
  if(n % k == 0)
  {
    for(int i = 1; i < list.size(); i++)
    {
      if(list[i] < temp)
      {
        temp = list[i];
      }
    }
  }
  else
  {
    for(int i = 1; i < list.size(); i++)
    {
      if(list[i] > temp)
      {
        temp = list[i];
      }
    }
  }
  if((temp * k) > n){
    cout << 0;
  }
  else if(n == 0)
  {
    cout << 0;
  }
  else{
    cout << temp;
  }
*/
  cout << tempmax;
  return 0;
}
