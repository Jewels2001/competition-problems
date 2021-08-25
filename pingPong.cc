# include <iostream>
# include <vector>
# include <string>
using namespace std;

int main()
{
  int points;
  cin >> points;
  vector<string> names;
  int countY = 0;
  int countN = 0;
  string y = "Yraglac";
  string n = "Notnomde";
  string winnerY;
  string winnerN;
  int greatestY = 0, greatestN = 0;
  for(int i = 0; i < points; i++)
  {
    string current;
    cin >> current;
    names.push_back(current);
    if(current.compare(y) == 0)
    {
      countY++;
    }
    else
    {
      countN++;
    }
    if(countY > countN && (countY - countN) > greatestY)
    {
      greatestY = (countY - countN);
    }
    if(countN > countY && (countN - countY) > greatestN)
    {
      greatestN = (countN - countY);
    }
    if(greatestN > greatestY)
    {
      winnerY = "Notnomde";
    }
    else if(greatestY > greatestN)
    {
      winnerY = "Yraglac";
    }
    else
    {
      winnerY = "tie";
    }
  }
  string current = names[0];
  int count = 1;
  int conY = 0, conN = 0;
  for(int i = 1; i < names.size(); i++)
  {
    if((current.compare(names[i]) == 0) || ((i + 1) == names.size()))
    {
      count++;
      if((i + 1) == names.size())
      {
        if(current.compare(y) == 0 && (count > conY))
        {
          conY = count;
        }
        if(current.compare(n) == 0 && (count > conN))
        {
          conN = count;
        }
      }
    }

    else
    {
      if(current.compare(y) == 0 && (count > conY))
      {
        conY = count;
      }
      if(current.compare(n) == 0 && (count > conN))
      {
        conN = count;
      }
      current = names[i];
      count = 1;
    }
  }
  if(conY > conN)
  {
    winnerN = "Yraglac";
  }
  if(conN > conY)
  {
    winnerN = "Notnomde";
  }
  if(conY == conN)
  {
    winnerN = "Tie";
  }
  string answer;
  if(winnerN.compare(winnerY) == 0)
  {
    cout << "Agree" << endl;
  }
  else
  {
    cout << "Disagree" << endl;
  }
  return 0;
}
