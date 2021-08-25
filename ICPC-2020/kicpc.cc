#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int main () {
  int n, l, p;

  cin >> n >> l;
  int cars[n] = {0};
  cin >> p;

  int x;

  int distance = 0;
  int max = 0;

  for (int i = 0; i < p; i++) {
    cin >> x;

    //x is too great
    if(x >= l*n){
      cars[n-1]++;
      distance = x - (n*l) + (l/2);
    }
    //x is on the edge of a train car
    else if((x % l) == 0){
      cars[x/l]++;
      distance = (l/2);
    }
    //x is at the door
    else if((x % l) == (l/2)){
      cars[x/l]++;
      distance = 0;
    }
    //x is in between doors
    else{
      cars[x/l]++;
      distance = (abs( (x %l) - (l/2) ) );
    }

    /*
    //  x is too great
    if (x >= l *n) {
      cars[n-1]++;
      distance = x - (n*l) + (l/2);
      //  x is too small
    } else if ((x/l) <= 0) {
      cars[0]++;
      distance = abs(l / 2);
    } else {
      cars[x / l]++;
      distance = abs((l / 2) - x % l);
    }
    */
    if(distance > max){
      max = distance;
    }
  }

  sort(cars, cars + n);

  cout << max << endl;
  cout << cars[n-1];
  return 0;
}
