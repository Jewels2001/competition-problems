#include <iostream>
using namespace std;

int main() {
  int n;
  int m;
  int num;
  int mostVotes = 0;
  int currentWinner = 0;
  int sum = 0;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> m;
    for(int j = 0; j < m; j++) {
      cin >> num;
      //cout << "num: " << num << endl;
      sum += num;
      if(num == mostVotes) {
        currentWinner = 0;
      }
      else if(num > mostVotes) {
        mostVotes = num;
        //cout << "most votes: " << mostVotes << endl;
        currentWinner = j + 1;
        //cout << "currentWinner: " << currentWinner << endl;
      }else {}
    }
    if(currentWinner == 0){
      cout << "no winner" << endl;
    }else if(mostVotes > (sum + 1) / 2) {
      cout << "majority winner " << currentWinner << endl;
    }else {
      cout << "minority winner " << currentWinner << endl;
    }
    sum = 0;
    mostVotes = 0;
    currentWinner = 0;
  }
  return 0;
}
