#include <bits/stdc++.h>

using namespace std;

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
        for(int i=0; i<a.length()-3; i++) {
            one = a[i];
            two = a[i+1];
            three = a[i+2];
            four = a[i+3];
            if(one == two || one == three || one == four) {
                continue;
            } else if(two == three || two == four || three == four) {
                continue;
            } else {
                pos = i+1+3;
                cout << i+1 << endl;
                break;
            }
            // if(yo.find(a[i]) == yo.end()) {
            //     yo.insert(a[i]);
            //     count++;
            //     pos = i;
            // } else {
            //     continue;
            // }
        }
        cout << pos << endl;
    }
}