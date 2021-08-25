#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
  int num, count;
  cin >> num;
  string name, temp;
  string test = " ";
  vector<string> understand;
  map<string, string> list;


  char x = cin.peek();
  if(x == '\n'){
    getline(cin, temp);
  }
  for(int i=0; i<num;i++){
    getline(cin, temp);
    size_t found = a.find(test, 0);
    name = temp.substr(0, found);
    size_t next = a.find(test, found);
    string speak = temp.substr(found, next);
    list.insert(pair<string, string>(name, speak));

    string known = temp.substr(found, string::npos);
    understand.push_back(known);  //create a vector with each entry a
    //list of understood languagues
  }

  for(int x=0; x<num; x++){
    string a = understand[x];
    size_t found = a.find(test, 0);
    string one = temp.substr(0, found);

    for(int y=1; y<num; y++){
      string b = understand[y];
      size_t found = a.find(test, 0);
      string two = temp.substr(0, found);
      if(one == two){

      }
      else{

      }

    }

    string one =

  }



    if(vector[]) == 1){} //if only speak 1 and understand 0
        // check to ensure at least one other speaks same 1
        //else count++;

      //if no one else speaks same, then check whether num understand >= 1
      //if so, check whether at least one other speaks 2 AND understands 1

      //if successful, pair++ and skip those two for check for rest.




  return 0;
}
