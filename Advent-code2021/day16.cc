#include <bits/stdc++.h>
using namespace std;

string packet = "";

void readHead(string six) {

}

void readID(char one) {

}

void countPackets() {
  
}

int main() {
  char z;

  while(cin >> z) {
    if(z == '0')
      cout << "0000";
      else if(z == '1')
      cout <<"0001";
    else if(z == '2')
    cout << "0010";
    else if(z == '3')
    cout << "0011";
    else if(z == '4')
    cout << "0100" ;
    else if(z == '5')
    cout << "0101" ;
    else if(z == '6')
    cout << "0110" ;
    else if(z == '7')
    cout << "0111" ;
    else if(z == '8')
    cout << "1000" ;
    else if(z == '9')
    cout << "1001" ;
    else if(z == 'A')
    cout << "1010" ;
    else if(z == 'B')
    cout << "1011" ;
    else if(z == 'C')
    cout << "1100" ;
    else if(z == 'D')
    cout << "1101";
    else if(z == 'E')
    cout << "1110";
    else if(z == 'F')
    cout << "1111";
  }
  return 0;
}
