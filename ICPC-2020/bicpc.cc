#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double binary_to_decimal(string s) {
    int k = 1;
    double decimal = 0.0;
    for(int i = 2; i < s.size(); i++){
        if (s[i] == '1')
            decimal += (1 / (pow(2, k)));
        k++;
    }
    return decimal;
}

int main() {
  int length;
  double d;
  cin >> length >> d;

  string k;
  cin >> k;
  double num = binary_to_decimal(k);

  double pa = d/8;
  double pb = 1 - pa;

  double temp = (k+)

  if(



  )

  for(int i=0;i<15;i++){
    double a=0,b=0,c=0;
    c=a+ pa*(b-a);

  }















    return 0;
}
