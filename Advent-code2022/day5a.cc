#include <bits/stdc++.h>

using namespace std;

vector<stack<char>> woo (9, stack<char>());


int main() {
    for(int i=0; i<9; i++) {
        char poop = 'a';
        while(poop != '.') {
            cin >> poop;
            if(poop == '.') {
                continue;
            }
            woo[i].push(poop);
        }
        cout << "next line" << endl;
    }
    cin.ignore(1, '\n');
    // string s;
    // for(int i=0;i<8; i++) {
    //     getline(cin, s);
    //     stringstream a;
    //     a << s;
    //     char temp;
    //     while(a >> temp) {
    //         if(temp == '[' || temp == ']') {
    //             continue;
    //         }

    //     }
    // }
    // getline(cin, s)

    for(int i=0; i<9; i++) {
        stack<char> dump = woo[i];
        for(dump; !dump.empty(); dump.pop()) {
            cout << dump.top() << " ";
        }
        cout << '\n' << endl;
    }
 
    string s;
    while(getline(cin, s)) {
        string temp1;
        int num, start, end;
        stringstream aa;
        aa << s;
        aa >> temp1 >> num >> temp1 >> start >> temp1 >> end;
        for(int i=0; i<num; i++) {
            char yo = woo[start-1].top(); woo[start-1].pop();
            woo[end-1].push(yo);
        }
    }

    for(int i=0; i<9; i++) {
        cout << woo[i].top();
    }
    cout << endl;



}