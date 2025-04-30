#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    while(getline(cin, line)) {
        stringstream s;
        s << line;
        string word;
        regex num("\d+:");
        vector<string> color {"red", "blue", "green"};
        while(s >> word) {
            if (regex_match(word, num)) {

            }
        }
    }

}