# include <iostream>
# include <cmath>
using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  if ((a > b) && (b > c) || (c > b) && (b > a))
  {
    if(abs(a - b) == abs(b - c))
      cout << "cruised" << endl;
    else if(abs(a - b) < abs(b - c))
      cout << "accelerated" << endl;
    else if(abs(a - b) > abs(b - c))
      cout << "breaked" << endl;
  }
  else if((a == b) && (b == c))
  {
    cout << "cruised" << endl;
  }
  else
  {
    cout << "turned" << endl;
  }
  return 0;
}
