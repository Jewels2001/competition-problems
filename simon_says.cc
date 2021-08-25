#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


int main(){
  int num;
  string test = "Simon says";
  string temp, space;
  cin >> num;
  char x = cin.peek();
  if(x == '\n'){
    getline(cin, temp);
  }

  for(int i=0; i<num; i++){
    getline(cin, temp);
    string a = temp.substr (0, 10);
    size_t found = a.find(test, 0);
    if(found!=string::npos){
    string b = temp.substr(10, 100);

    //temp >> a >> b;
    //if((a == "Simon") && b == "says"){
    //  getline(cin, temp);
      //if(temp.begin() == ' '){
      //  temp.erase(0, 1);
    //  }
      cout << b << endl;
      continue;
    }
    else{
      continue;
    }
  }
  return 0;
}
