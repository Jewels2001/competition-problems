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
    int count = 0;
    string current = "";
    map<char, int> smh;
    set<char> aaah;
    while(getline(cin, r)) {
        count++;
        if(count < 3) {
            //current += r;
            for(int i=0; i<r.length(); i++) {
                if(aaah.find(r[i])==aaah.end()) {
                    cout << "SMH" << endl;
                    smh[r[i]]++;
                    aaah.insert(r[i]);
                }
            }
            aaah.clear();
            continue;
        }
        aaah.clear();
        for(int i=0; i<r.length(); i++) {
                if(aaah.find(r[i])==aaah.end()) {
                    cout << "SMH" << endl;
                    smh[r[i]]++;
                    aaah.insert(r[i]);
                }
            }
        //cout << current << endl;
        int s = r.length();
        //s = s / 2;
                char letter = '.';

        for(auto a : smh) {
            cout << a.first << " " << a.second << endl;
            if(a.second == 3) {
                cout << "HEER" << endl;
                letter = a.first;
                break;
            }
        }
        // for(int i=0; i<s; i++) {
        //     char temp = r[i];
        //     for(int j=s; j<2*s; j++) {
        //         if(temp == r[j]) {
        //             letter = temp;
        //             cout << "HERE" << endl;
        //             cout << temp << " " << letter << endl;
        //             break;
        //         }
        //     }
        //     if(letter == temp) {
        //         break;
        //     }
        // }
        cout << "L:" << letter << endl;
        total += (wow[letter]);
        cout << "YO:" <<  wow[letter] << endl;
        count = 0;
        current = "";
        aaah.clear();
        smh.clear();
    }
    cout << total << endl;
}