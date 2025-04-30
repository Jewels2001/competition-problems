#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    int sum = 0;
    while(getline(cin, line)) {
        bool seen = false;
        string a = "0";
        string b = "-1";
        for(int i=0; i<line.length(); i++) {
            if(isdigit(line[i])) {
                if(!seen) {
                    a = line[i];
                    seen = true;
                } else {
                    b = line[i];
                }
            }
        }
        if(b == "-1") {
            b = a;
        }
        string c = a+b;

        sum += stoi(c);
    }
    cout << sum << endl;
}