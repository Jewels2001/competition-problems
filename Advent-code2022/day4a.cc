#include <bits/stdc++.h>

using namespace std;


int main() {
    string a;
    string abc;
    while(getline(cin, a)) {
        stringstream ss;
        ss << a;
        int a1, a2, b1, b2;
        char temp;
        ss >> a1 >> temp >> a2 >> temp >> b1 >> temp >> b2;
        int i=1;
        while(i <= 9) {
            if(i >= a1 || i <= a2) {
                abc += char(i);
            } else {
                abc += '.';
            }
        }
        if(search(begin(abc), end(abc)))
        

    }    
}