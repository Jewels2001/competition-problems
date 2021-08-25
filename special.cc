/**
* Adapted from Howard's code at
* https://github.com/HowardChengUleth/Contest/blob/master/kattis/divideby100.cc
*/
# include <iostream>
# include <string>

using namespace std;

int main()
{
  //we take the input as strings because the max input is too large for C++
  //to handle, and in other languages that can handle it, you will get a time
  //limit exceeded error
  string numerator, denominator;
  cin >> numerator >> denominator;

  //get the length of the number being divided
  int numeratorSize = numerator.length();
  //we subtract one from denominator size because we want to know
  //how many zeros
  int denominatorSize = denominator.length() - 1;

  //if the dividing number is greater than the divided number, then the
  //quotient will be less than 1, so we need to add enough zeros to the beginning
  //before we output the numerator we recieved as input
  if(denominatorSize + 1 > numeratorSize)
  {
    numerator = string((denominatorSize + 1) - numeratorSize, '0') + numerator;
    numeratorSize = numerator.length();
  }

  //we need to break the quotient into two substrings, one with the digits that
  //will be printed before the decimal and one with the digits that will be printed
  //after the decimal
  string digitsBefore = numerator.substr(0, numeratorSize - denominatorSize);
  string digitsAfter = numerator.substr(numeratorSize - denominatorSize);

  //we need to get rid of any trailing zeros in the output
  while(digitsAfter[digitsAfter.length() - 1] == '0')
  {
    digitsAfter.erase(digitsAfter.length() - 1);
  }
  //if there are no digits after the decimal, we don't need a decimal and
  //we don't need to print the digitsAfter substring, so we use an if/else
  //statement to determine this
  if(digitsAfter != "")
  {
    cout << digitsBefore << "." << digitsAfter << endl;
  }
  else
  {
    cout << digitsBefore << endl;
  }

  return 0;
}
