#include <bits/stdc++.h>

using namespace std;


int main() {
    string a;
    string abc;
    int count = 0;
    while(getline(cin, a)) {
        stringstream ss;
        ss << a;
        int a1, a2, b1, b2;
        char temp;
        ss >> a1 >> temp >> a2 >> temp >> b1 >> temp >> b2;
        int i=1;
        cout << a1 << " " << a2 << " " << b1 <<  " " << b2 << endl;
        // if(b1 <= a1 && a2 <= b2) {
        //     count++;
        //     cout << "added1" << endl;
        // } else if(a1 <= b1 && b2 <= a2) {
        //     count++;
        //     cout << "added2" << endl;
        // } else if(a1 <= b1 && b1 <= a2) {
        //     count++;
        // } else if(b1 <= a1 && a2 <= b1) {
        //     count++;
        // }
        if(a2 >= b1 && b1 >= a1) {
            count++;
        } else if(b2 >= a1 && a1 >= b1) {
            count++;
        }
        // while(i <= 9) {
        //     if(i >= a1 || i <= a2) {
        //         abc += char(i);
        //     } else {
        //         abc += '.';
        //     }
        // }
        // if(search(begin(abc), end(abc)))
        

    }
    cout << count << endl;
}