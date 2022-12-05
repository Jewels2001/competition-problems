#include <bits/stdc++.h>

using namespace std;

map<char, int> wow;

int main() {
    for(int i='A'-'A'; i<27; i++) {
        wow[i+'A'] = i+27; 
    }
    for(int i='a'-'a'; i<27; i++) {
        wow['a'+i] = i+1; 
    }
    string r;
    int total = 0;
    cout << wow['z'] << endl;
    // 'A' - '0' - 17
    // 'a' - '0' - 49
    while(getline(cin, r)) {
        int s = r.length();
        s = s / 2;
        char letter = '.';
        for(int i=0; i<s; i++) {
            char temp = r[i];
            for(int j=s; j<2*s; j++) {
                if(temp == r[j]) {
                    letter = temp;
                    cout << "HERE" << endl;
                    cout << temp << " " << letter << endl;
                    break;
                }
            }
            if(letter == temp) {
                break;
            }
        }
        total += wow[letter];
        count = 0;
    }
    cout << total << endl;
}