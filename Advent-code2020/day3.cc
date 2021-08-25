#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
  vector<vector<char>> snow( 323, vector<char> (32));
  int trees = 0;
  int num, a, b;
  char land;
  string row;

  for(int i=0; i<323; i++){
    for(int j=0;j<32;j++){
      cin.get(land);
      snow[i][j] = land;
    }
  }
  int size = snow.size();
  cout << "The size of the vector is: " << size << endl;

  //check
  for(int i=1; i<323; i++){
    for(int j=0;j<32;j++){
      if(snow[i][j] == '#'){
        trees++;
        cout << "Tree on row " << i << " and col " << j << endl;
        j += 2;
        if(j > 31){
          j -= 31;
        }
        break;
      }
      else{
        j += 2;
        if(j > 31){
          j -= 31;
        }
        continue;
    }

    }
  }
  cout << "There are " << trees << " trees." << endl;

  return 0;
}
