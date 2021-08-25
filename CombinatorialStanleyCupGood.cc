#include <bits/stdc++.h>
using namespace std;

long long int check(int a, int c, int d);

int main() {
  long long int n;
  cin >> n;
  long long int a = n%4;
  //long long int b = (n/4) + 1;
  long long int c = n%16;

  long long int d = (n/16) +1;


  long long int e = (n/16);

  long long int k = e%4;

  long long int f = e%16;
  long long int j = 0;


  long long int apples =0;
  //j = check(e, f, d);

  long long int ans;

  if(k == 0){ //a
    //lowest
    if(f==0){ //c
      j = 1*e; //d
    }
     else if((f==4) || (f==8)){
       j = 2*e;
     }
     else if(f==12){
       j = 4*e;
     }
  }
  else if(k == 3){
    //highest
    if(f==3){
      j = 4*e;
    }
     else if((f==7) || (f==11)){
       j = 8*e;
     }
     else if(f==15){
       j = 16*e;
     }
  }
  else{
    if((f==1) || (f==2)){
      j = 2*e;
    }
     else if((f==13) || (f==14)){
       j = 8*e;
     }
     else{
       j = 4*e;
     }
  }
  cout << " J:" << j << endl;

  apples = check(a,c,j);
  cout << apples;

  return 0;
}

long long int check(int a, int c, int d){
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
    return ans;
}
