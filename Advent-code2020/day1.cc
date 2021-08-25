#include <iostream>
#include <vector>

using namespace std;

int main(){
  int one;
  vector<int> data;
  int ans;

  do{
    cin >> one;
    data.push_back(one);
  } while (one);

  int a = data.size();
  cout << "The vector size is: " << a << endl;


  for(int i=0; i<a; i++){
    int temp = data[i];
    for(int j=1; j<a; j++){
      int next = data[j];
      for(int x=2; x<a; x++){
        int super = data[x];
        if(temp + next + super == 2020){
          ans = (temp*next)*super;
          cout << temp << " * " << next << " * " << super << " = " << ans << endl;
        }
      }
    }
  }
  return 0;
}
