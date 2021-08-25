#include <iostream>
#include <vector>

using namespace std;


int main(){
  int events;
  int day1, day2;
  int answer = 0;
  vector<int> days;
  vector<int> food;
  cin >> events;

  for(int i=0; i<events; i++){
    cin >> day1 >> day2;
    int temp = day1;
    int x = (day2-day1)+1;
    if(x==0){
      x=1;
    }
    for(int j=0;j<x;j++){
      days.push_back(temp);
      if(temp < day2){
        temp++;
      }
    }
  }

  for(unsigned int n=0; n<days.size(); n++){
    for(unsigned int j=n+1; j<(days.size()); j++){
      if(days[n] == days[j]){
        days.erase(days.begin()+j);
      }
    }
  }
  answer = days.size();
  if(answer > 365){
    answer = 365;
  }
  cout << answer;
  return 0;
}
