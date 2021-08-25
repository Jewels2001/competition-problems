#include <bits/stdc++.h>
using namespace std;


int main() {
  long long int n;
  cin >> n;
  long long int a = n%4;
  //long long int b = (n/4) + 1;
  long long int c = n%16;
  long long int d = (n/16) + 1;

  long long int ans = 0;

  if(a == 0){
    //lowest
    if(c==0){
      ans = 1*d;
    }
     else if((c==4) || (c==8)){
       ans = 2*d;
     }
     else if(c==12){
       ans = 4*d;
     }
  }
  else if(a == 3){
    //highest
    if(c==3){
      ans = 4*d;
    }
     else if((c==7) || (c==11)){
       ans = 8*d;
     }
     else if(c==15){
       ans = 16*d;
     }
  }
  else{
    if((c==1) || (c==2)){
      ans = 2*d;
    }
     else if((c==13) || (c==14)){
       ans = 8*d;
     }
     else{
       ans = 4*d;
     }
  }
  cout << ans;

  return 0;
}
