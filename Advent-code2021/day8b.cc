#include <bits/stdc++.h>
using namespace std;


string check7(string one, string seven) {
  string a = "";
  string cf = one.substr(0,1);
  string fc = one.substr(1,1);
  for(int i=0;i<3;i++) {
    if((cf[0] != seven[i]) && (fc[0] != seven[i])){
      a += seven[i];
    }
  }
  return a;
}

string check4(string one, string four) {
  string bd = "";
  char cf  = one[0];
  char fc = one[1];
  for(int i=0; i<4;i++) {
    if((cf != four[i]) && (fc != four[i])){
      bd += four[i];
    }
  }
  return bd;
}

string check9ge(vector<string> sixes, string a, string four) {
  string ge = "";
  char f = four[0];
  char o = four[1];
  char u = four[2];
  char r = four[3];
  int size = sixes.size();
  for(int i=0; i<size;i++) {
    if(
      (sixes[i].find(f) == string::npos) || (sixes[i].find(o) == string::npos) ||
      (sixes[i].find(u) == string::npos) || (sixes[i].find(r) == string::npos)) {
        continue;
      }
    for(int j=0; j<6; j++) {
      if((a[0] != sixes[i][j]) && (f != sixes[i][j]) && (o != sixes[i][j]) &&
        (u != sixes[i][j]) && (r != sixes[i][j])) {
        ge += sixes[i][j];
      }
    }
    for(char oop='a'; oop<='g'; oop++) {
      if(sixes[i].find(oop) == string::npos) {
        ge+= oop;
      }
    }
  }
    // sixes.erase(sixes.begin()+i);
  return ge;
}

string check5fc(vector<string> fives, string a, string bd, string g, string one) {
  string fc = "";
  string b = bd.substr(0,1);
  string d = bd.substr(1,1);
  int size = fives.size();
  for(int i=0;i<size;i++) {
    if((fives[i].find(b) == string::npos) || (fives[i].find(d) == string::npos)) {
      continue;
    }
    for(int j=0; j<5;j++) {
      if((b[0] != fives[i][j]) && (d[0] != fives[i][j]) && (a[0] != fives[i][j]) &&
        (g[0] != fives[i][j])) {
        fc += fives[i][j];
      }
    }
    if(one[0] != fc[0]) {
      fc += one[0];
    }
    else {
      fc += one[1];
    }
  }
  return fc;
}

string check0(vector<string> sixes, string db, string a, string c, string e, string f, string g) {
  string bd = "";
  int size = sixes.size();
  for(int i=0;i<size;i++) {
    if((sixes[i].find(c) == string::npos) || (sixes[i].find(e) == string::npos)) {
      continue;
    }
    for(int j=0; j<6;j++) {
      if((a[0] != sixes[i][j]) && (c[0] != sixes[i][j]) && (e[0] != sixes[i][j]) &&
        (f[0] != sixes[i][j]) && (g[0] != sixes[i][j])) {
        bd += sixes[i][j];
      }
    }
    if(db[0] != bd[0]) {
      bd += db[0];
    }
    else {
      bd += db[1];
    }
  }
  return bd;
}

bool findStr(string code, string num) {
  int len = num.length();
  for(int i=0; i<len;i++) {
    if(code.find(num[i]) == string::npos) {
      return false;
    }
  }
  return true;
}

int main() {
  vector<string> data;
  int ans = 0;

  //end-of-file input on windows is ctrl-z
  string signal;
  string output;
  while(getline(cin, signal, '|')) {
    stringstream ss(signal);
    getline(cin, output);
    stringstream ss1(output);
    cout << "signal: " << signal << endl;
    cout << "output: " << output << endl << endl;

    string oneVal = "";

    vector<string> fives;
    vector<string> sixes;

    //count the number of 2,3,4,7 long strings for part one
    string zero, one, two, three,four,five,six,seven,eight,nine;
    for(int i=0; i<10;i++) {
      string temp;
      ss >> temp;
      if(temp.length() == 2) {
        one = temp;
      } else if(temp.length() == 3) {
        seven = temp;
      } else if(temp.length() == 4) {
        four = temp;
      } else if(temp.length() == 7) {
        eight = temp;
      } else if(temp.length() == 5) {
        fives.push_back(temp);
      } else if(temp.length() == 6) {
        sixes.push_back(temp);
      }
      data.push_back(temp);
    }

    //check which are in 7 - find a
    string a = check7(one, seven);

    //check which are same in 4
    string db = check4(one, four);

    //check sixes for 9
    string ge = check9ge(sixes, a, four);
    string g = ge.substr(0,1);
    string e = ge.substr(1,1);

    //check which are in 5
    string fc = check5fc(fives, a, db, g, one);
    string f = fc.substr(0,1);
    string c = fc.substr(1,1);

    //check sixes for 0 (find d)
    string bd = check0(sixes, db, a, c, e, f,g);
    string b = bd.substr(0,1);
    string d = bd.substr(1,1);

    cout << "A: " << a << " " <<
            "B: " << b << " " <<
            "C: " << c << " " <<
            "D: " << d << " " <<
            "E: " << e << " " <<
            "F: " << f << " " <<
            "G: " << g << " " <<
            endl;

    //sixes
    zero = "" + a + b + c + e + f + g;
    six = "" + a + b + d + e + f + g;
    nine = "" + a + b + c + d + f + g;
    //fives
    two = "" + a + c + d + e + g;
    three = "" + a + c + d + f + g;
    five = "" + a + b + d + f + g;


    //output
    cout << "output: " << output << ": ";
    for(int j=0; j<4;j++) {
      string t;
      while(ss1 >> t) {
        // cout << "t: " <<t << endl;
        if(t.length() == 2) {
          oneVal+= "1";
        } else if(t.length() == 3) {
          oneVal+= "7";
        } else if(t.length() == 4) {
          oneVal+= "4";
        } else if(t.length() == 7) {
          oneVal+= "8";
        } else if(t.length() == 6) {
          if(findStr(t, zero)) {
              oneVal+= "0";
          } else if(findStr(t, six)) {
              oneVal+= "6";
          } else if(findStr(t, nine)) {
              oneVal += "9";
          } else {
            oneVal += "+";
          }
        } else if(t.length() == 5) {
          if(findStr(t, two)) {
            oneVal += "2";
          } else if(findStr(t, three)) {
            oneVal += "3";
          } else if(findStr(t, five)) {
            oneVal += "5";
          } else {
            oneVal += "-";
          }
        }
        else {
          oneVal += "_";
        }
      }
    }
       cout << oneVal << endl;
       cout << "int: " << stoi(oneVal) << endl;
       ans += stoi(oneVal);
       cout << "ans: " << ans << endl;

   }
   cout << "ans: " << ans << endl;
   //part 2:
   //find smallest string's length
   //mark those characters for a given #
   //the letter in 7 (3chars) and not 1 (2chars) is top or aaaa
   //

  return 0;
}
