#include <bits/stdc++.h>
using namespace std;

int main(){
  int p = 0, temp;
  cin >> p;
  int ans = 0;
  vector<int> prices;
  bool sell = 0;
  int day = -1;


  for(int i=0; i<p; i++){
    cin >> temp;
    prices.push_back(temp);
  }
  prices.push_back(-1);
  //vector<int> second (prices);
  //sort(second.begin(), second.end());
  //ans = second[second.size()-1];

  if(p == 1){
    ans = 0;
    cout << ans;
    return 0;
  }

  int min = prices[0];
  int max = prices[0];


  int buy = prices[0];
  int j=1;
label:
  for(; j<p; j++){
    int current = prices[j];
    int next = prices[j+1];
    if(buy > 1000){
      buy = -1;
    }
    if((next == -1) && ( p>2)){
      cout << ans;
      return 0;
    }
    if(j <= day || sell == 1){
      sell = 0;
      day = -1;
      j++;
      goto label;
    }
    if(buy <= current){
      if(next > current){
        if(prices[j+2] < next){
          ans += (next - buy);
          sell = 1;
          day = j+2;
          buy = prices[j+3];
          j++;
          goto label;
        }
        else if(prices[j+2] >= next){
          j++;
          goto label;
        }
      }
      else if(next <= buy && prices[j+2] > current){
        buy = next;
        j++;
        goto label;
      }
      else if(next == current){
        j++;
        goto label;
      }
      else{
        ans += (current - buy);
        sell = 1;
        day = j+2;
        buy = prices[j+2];
        j++;
        goto label;
      }
    }
    else{
      buy = current;
    }



    /*
    if(prices[j] <= min){
      min = prices[j];
    }
    if(prices[j] >= max){
      max = prices[j];
    }
    if(max)
    if(j == day){
      sell = 0;
    }

    if((prices[j+1] > prices[j]) && (prices[j+2] <= prices[j+1])){
      if(sell == 0){
        ans += (prices[j+1] - prices[j]);
        sell = 1;
        day = j+1;
      }
    }
    */

  }
  cout << ans;

  return 0;
}
