#include <iostream>
#include <cmath>
using namespace std;

int main() {
  //l is an even number
  int n, l, p, x;
  cin >> n >> l >> p;
  int cars[n] = {0};
  int distance = 0, furthest = 0, greatestP = 0;
  for(int i = 0; i < p; i++) {
    cin >> x;
    if((x / l) == 0) {
      cars[0]++;
      if(cars[0] > greatestP) {
        greatestP = cars[0];
      }
      distance = (l / 2) - x;
    }else if(x > n * l) {
      cars[n - 1]++;
      if(cars[n - 1] > greatestP) {
        greatestP = cars[n - 1];
      }
      distance = x - (n * l) + (l / 2);
    }else{
      cars[(x / l) - 1]++;
      //cout << "car: " << (x / l) << endl;
      if(cars[(x / l) - 1] > greatestP) {
        greatestP = cars[(x / l) - 1];
      }
      if((x % l) > (l / 2)) {
      distance = (x % l) - (l / 2);
      }//else if(x == 0){
      //distance = (l / 2);
      //}
      else{
        distance = (l / 2) - x % l;
      }
    }
    if(distance > furthest) {
      furthest = distance;
    }
  }
    //cout << i + 1 << ": " << cars[i] << endl;
  cout << furthest << endl;
  cout << greatestP << endl;
  return 0;
}
