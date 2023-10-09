/*
Problem J in RMRC 22
Simple brute force every year, check whether the current year plus the offset
from being d years ago is divisible /modulo y, the time every cycle takes.
(worded weird, cycle length is "how many years it takes sun to be back in position" )
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int ds, ys, dm, ym;
    cin >> ds >> ys >> dm >> ym;
    for(int i=1; i<5001; i++) {
        if((i + dm) % ym == 0 && (i + ds) % ys == 0) {
            cout << i << endl;
            return 0;
        }
    }
}