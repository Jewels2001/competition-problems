#include <bits/stdc++.h>

using namespace std;

const int MAX_CHAR = 256;

bool uniqueCharacters(string str)
{
 
    // If length is greater than 265,
    // some characters must have been repeated
    if (str.length() > MAX_CHAR)
        return false;
 
    bool chars[MAX_CHAR] = { 0 };
    for (int i = 0; i < str.length(); i++) {
        if (chars[int(str[i])] == true)
            return false;
 
        chars[int(str[i])] = true;
    }
    return true;
}


int main() {
    string a;
    while(getline(cin, a)) {
        //set<char> yo;
        char one = '.';
        char two = '.';
        char three = '.';
        char four = '.';

        int count = 0;
        int pos = 0;
        for(int i=0; i<a.length()-13; i++) {
            string sub = a.substr(i, 14);
            if (uniqueCharacters(sub)) {
                cout << i+1 << endl;
                pos = i+1+13;
                break;
            }
        }
        cout << pos << endl;
    }
}