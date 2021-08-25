#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
int cases;
cin >> cases;
int j =0;
do{
vector <string> category;
vector <string> name;
int count = 0;

int num;
cin >> num;

for(int i=0; i<num; i++){
  string a, b;
  cin >> a >> b;
  name.push_back (a);
  category.push_back (b);
  count++;
}

cout << count << endl;
for(int x =0; x< category.size(); x++){
  string temp = category[x];
  for(int n =1; n<category.size(); n++){
    if (temp == category[n]){
      count--;
    }
  }
}

cout << name.size() << endl;
cout << count << endl;
int p = name.size() * count;

cout << p << endl;

j++;
}while(j < cases);


return 0;
}
